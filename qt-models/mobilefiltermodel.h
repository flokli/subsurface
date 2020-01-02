// SPDX-License-Identifier: GPL-2.0
#ifndef MOBILEFILTERMODEL_H
#define MOBILEFILTERMODEL_H

#include "divetripmodel.h"
#include <QSortFilterProxyModel>

class MobileFilterModel : public QSortFilterProxyModel {
	Q_OBJECT
public:
	static MobileFilterModel *instance();
	bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

	void toggle(int row);
	Q_INVOKABLE int shown(); // number dives that are accepted by the filter
signals:
	void currentDiveChanged(QModelIndex index);
private slots:
	void currentDiveChangedSlot(QModelIndex index);
private:
	int mapRowToSource(int row);
	MobileFilterModel();
};

#endif