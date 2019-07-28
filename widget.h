#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int n);
    int money{0};

private slots:
    void on_Add10_clicked();

    void on_Add50_clicked();

    void on_Add100_clicked();

    void on_Add500_clicked();

    void on_co100_clicked();

    void on_te150_clicked();

    void on_la200_clicked();

    void on_change_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
