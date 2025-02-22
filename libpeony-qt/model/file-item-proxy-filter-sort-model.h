/*
 * Peony-Qt's Library
 *
 * Copyright (C) 2019, Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Authors: Yue Lan <lanyue@kylinos.cn>
 * Authors: Meihong He <hemeihong@kylinos.cn>
 *
 */

#ifndef FILEITEMPROXYFILTERSORTMODEL_H
#define FILEITEMPROXYFILTERSORTMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "peony-core_global.h"

namespace Peony {

class FileItem;
class FileItemModel;

class PEONYCORESHARED_EXPORT FileItemProxyFilterSortModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    enum FilterFileType{
        ALL_TYPE,
        FILE_FOLDER,
        PICTURE,
        VIDEO,
        TXT_FILE,
        AUDIO,
        OTHERS
    };
    Q_ENUM(FilterFileType)
    enum FilterFileModifyTime{
        ALL_TIME,
        TODAY,
        THIS_WEEK,
        THIS_MONTH,
        THIS_YEAR,
        YEAR_AGO
    };
    Q_ENUM(FilterFileModifyTime)
    enum FilterFileSize{
        ALL_SIZE,
        TINY,
        SMALL,
        MEDIUM,
        BIG,
        LARGE
    };
    Q_ENUM(FilterFileSize)

    const QString Folder_Type = "inode/directory";
    const QString Image_Type = "image/";
    const QString Video_Type = "video/";
    const QString Text_Type = "text/";
    const QString Audio_Type = "audio/";

    explicit FileItemProxyFilterSortModel(QObject *parent = nullptr);
    void setSourceModel(QAbstractItemModel *model) override;
    void setShowHidden(bool showHidden);
    void setFilterConditions(int fileType=0, int modifyTime=0, int fileSize=0);

    FileItem *itemFromIndex(const QModelIndex &proxyIndex);
    QModelIndex getSourceIndex(const QModelIndex &proxyIndex);
    const QModelIndex indexFromUri(const QString &uri);

    QStringList getAllFileUris();
    QModelIndexList getAllFileIndexes();

public Q_SLOTS:
    void update();

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
    bool startWithChinese(const QString &displayName) const;
    bool checkFileTypeFilter(QString type) const;
    bool checkFileModifyTimeFilter(QString modifiedDate) const;
    bool checkFileSizeFilter(quint64 size) const;

private:
    bool m_show_hidden = false;
    const int ALL_FILE = 0;
    const quint64 K_BASE = 1000;
    int m_show_file_type=ALL_FILE, m_show_modify_time=ALL_FILE, m_show_file_size=ALL_FILE;
};

}

#endif // FILEITEMPROXYFILTERSORTMODEL_H
