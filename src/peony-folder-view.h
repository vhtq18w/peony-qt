#ifndef PEONYFOLDERVIEW_H
#define PEONYFOLDERVIEW_H

#include <libfm-qt/folderview.h>
#include <libfm-qt/foldermodel.h>

#include <libfm-qt/proxyfoldermodel.h>
#include <libfm-qt/cachedfoldermodel.h>

class PeonyFolderView : public Fm::FolderView
{
    Q_OBJECT
public:
    explicit PeonyFolderView(QWidget *parent = nullptr);

public Q_SLOTS:
    void onFileClicked(int type, const std::shared_ptr<const Fm::FileInfo>& fileInfo) override;

Q_SIGNALS:
    void updatePathBarRequest(const Fm::FilePath path);
    void pushBackListRequest(const Fm::FilePath path);

private:
    Fm::FolderModel *m_model = nullptr;
    Fm::ProxyFolderModel *m_proxy_model = nullptr;
    Fm::CachedFolderModel *m_cache_model = nullptr;
};

#endif // PEONYFOLDERVIEW_H
