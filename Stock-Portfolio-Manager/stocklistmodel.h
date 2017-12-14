#ifndef STOCKLISTMODEL_H
#define STOCKLISTMODEL_H

#include <QAbstractListModel>
#include <vector>
using std::vector;
#include "stock.h"

class StockListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit StockListModel(vector<Stock> &stocks, QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    vector<Stock> &stocks;

};

#endif // STOCKLISTMODEL_H
