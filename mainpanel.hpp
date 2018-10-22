#ifndef MAINPANEL_HPP
#define MAINPANEL_HPP

#include <QWidget>

namespace Ui {
    class mainpanel;
    }
class mainpanel : public QWidget
{
    Q_OBJECT

public:
    explicit mainpanel(QWidget *parent = nullptr);
    ~mainpanel();
public:
    void resizeEvent(QResizeEvent* event);
private:
    Ui::mainpanel *ui;
};

#endif // MAINPANEL_HPP
