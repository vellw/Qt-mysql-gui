#ifndef MAINPANEL_HPP
#define MAINPANEL_HPP

#include <QWidget>

namespace Ui {
    class mainpanel;
    }
class QTreeView;
class QTabWidget;
class QStandardItemModel;
class mainpanel : public QWidget
{
    Q_OBJECT

public:
    explicit mainpanel(QWidget *parent = nullptr);
    ~mainpanel();
public:
    //
    QTreeView * get_table_list();
    QTabWidget * get_query_tabs();
    QStandardItemModel * get_item_model();
private:
    Ui::mainpanel *ui;
    QTreeView * ptr_table_list;
    QStandardItemModel * ptr_item_model;
    QTabWidget * ptr_query_tabs;
};

#endif // MAINPANEL_HPP
