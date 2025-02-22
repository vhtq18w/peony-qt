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
 * Authors: Burgess Chang <brs@sdf.org>
 *
 */

#ifndef LIBPEONYPREVIEW_PDFTHUMBNAIL_H
#define LIBPEONYPREVIEW_PDFTHUMBNAIL_H

#include <QPixmap>
#include <QString>
#include <poppler-qt5.h>

class PdfThumbnail {
public:
  unsigned int pageNum;

  explicit PdfThumbnail(const QString &url, unsigned int pageNum = 0);
  ~PdfThumbnail();
  QPixmap generateThumbnail(unsigned int pageNum = 0);

private:
  QString shortUrl;
  Poppler::Document *documentPrivate = nullptr;
  Poppler::Page *pagePrivate = nullptr;
};

#endif // LIBPEONYPREVIEW_PDFTHUMBNAIL_H
