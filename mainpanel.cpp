#include "mainpanel.hpp"
#include "ui_mainpanel.h"

#include <QTreeView>
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>

mainpanel::mainpanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainpanel)
{
    ui->setupUi(this);
    ptr_query_tabs = ui->query_tabs;
    ptr_table_list = ui->table_list;

    ptr_item_model = new QStandardItemModel(ptr_table_list);

    ptr_table_list->setModel(ptr_item_model);  // 这里必须setmodel 否则显示不出来
    ptr_table_list->header()->setVisible(false);

    ptr_query_tabs->setTabText(0,tr("new"));
    ptr_query_tabs->removeTab(1);
}

mainpanel::~mainpanel()
{
    delete ui;
    if(ptr_query_tabs) delete ptr_query_tabs;
    if(ptr_table_list) delete ptr_table_list;
    if(ptr_item_model) delete ptr_item_model;
}

QTreeView *mainpanel::get_table_list()
{
    return ptr_table_list;
}

QTabWidget *mainpanel::get_query_tabs()
{
    return ptr_query_tabs;
}

QStandardItemModel *mainpanel::get_item_model()
{
    return ptr_item_model;
}
