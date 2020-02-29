#ifndef TODOMODEL_H
#define TODOMODEL_H
#include <QAbstractTableModel>
#include <vector>

class ToDoModel: public QAbstractTableModel
{
public:
    ToDoModel(QObject *parent);
    std::vector<QString> items;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void openFile (QString filePath);
};

#endif // TODOMODEL_H
