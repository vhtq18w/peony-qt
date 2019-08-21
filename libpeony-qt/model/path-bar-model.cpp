#include "path-bar-model.h"
#include "file-enumerator.h"
#include "file-info.h"
#include "file-utils.h"

using namespace Peony;

PathBarModel::PathBarModel(QObject *parent) : QStringListModel (parent)
{

}

void PathBarModel::setRootPath(const QString &path)
{
    setRootUri("file://" + path);
}

void PathBarModel::setRootUri(const QString &uri)
{
    if (m_current_uri == uri)
        return;

    auto file = wrapGFile(g_file_new_for_uri(uri.toUtf8().constData()));
    if (!g_file_query_exists(file.get()->get(), nullptr)) {
        return;
    }

    qDebug()<<"setUri"<<uri<<"raw"<<m_current_uri;

    beginResetModel();

    m_current_uri = uri;
    FileEnumerator e;
    e.setEnumerateDirectory(uri);
    e.enumerateSync();
    auto infos = e.getChildren();
    if (infos.isEmpty()) {
        endResetModel();
        return;
    }

    m_uri_display_name_hash.clear();
    QStringList l;
    for (auto info : infos) {
        //skip the independent file.
        if (!(info->isDir() || info->isVolume()))
            continue;

        l<<info->uri();
        QString display_name = FileUtils::getFileDisplayName(info->uri());
        m_uri_display_name_hash.insert(info->uri(), display_name);
    }
    setStringList(l);
    endResetModel();
}

QString PathBarModel::findDisplayName(const QString &uri)
{
    if (m_uri_display_name_hash.find(uri)->isNull()) {
        return FileUtils::getFileDisplayName(uri);
    } else {
        return m_uri_display_name_hash.value(uri);
    }
}
