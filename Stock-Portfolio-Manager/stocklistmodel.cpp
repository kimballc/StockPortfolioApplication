#include "stocklistmodel.h"

StockListModel::StockListModel(vector<Stock> &stocks, QObject *parent)
    : QAbstractListModel(parent), stocks(stocks)
{

}

int StockListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    else
        return stocks.size();
}

QVariant StockListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        std::string displayStock = stocks.at(index.row()).getTicker();
        return QVariant(QString::fromStdString(displayStock));
    }
    return QVariant();
}
