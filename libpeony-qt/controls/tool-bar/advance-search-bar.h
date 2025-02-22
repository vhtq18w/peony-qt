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
 * Authors: Meihong He <hemeihong@kylinos.cn>
 *
 */

#ifndef ADVANCE_SEARCH_BAR_H
#define ADVANCE_SEARCH_BAR_H

#include "advanced-location-bar.h"

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>

namespace Peony {

class FMWindow;

class AdvanceSearchBar : public QWidget
{
    Q_OBJECT
public:
    explicit AdvanceSearchBar(FMWindow *window, QWidget *parent = nullptr);

Q_SIGNALS:

public Q_SLOTS:
    void clearData();
    void browsePath();
    void searchFilter();
    void filterUpdate();
    void setShowHidden();
    void updateLocation();
    void pathChanged();

public:
    //advance search filter options
    QStringList m_file_type_list = {tr("all"), tr("file folder"), tr("image"), tr("video"), tr("text file"), tr("audio"), tr("others")};
    QStringList m_file_mtime_list = {tr("all"), tr("today"), tr("this week"), tr("this month"), tr("this year"), tr("year ago")};
    QStringList m_file_size_list = {tr("all"), tr("tiny(0-16K)"), tr("small(16k-1M)"), tr("medium(1M-100M)"), tr("big(100M-1G)"),tr("large(>1G)")};

protected:
    void init();

private:
    FMWindow *m_top_window;

    QWidget *m_filter;
    QLineEdit *m_advanced_key, *m_search_path;
    QComboBox *typeViewCombox, *timeViewCombox, *sizeViewCombox;

    QString m_advance_target_path, m_last_show_name;
    QList<QString> m_choosed_paths;
};

}

#endif // ADVANCE_SEARCH_BAR_H
