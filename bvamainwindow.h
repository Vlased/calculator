#ifndef BVAMAINWINDOW_H
#define BVAMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BVAMainWindow; }
QT_END_NAMESPACE

class BVAMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    BVAMainWindow(QWidget *parent = nullptr);
    ~BVAMainWindow();

private slots:

private:
    Ui::BVAMainWindow *ui;

private slots:
    void bvaDigitsButtons();
    void on_bvaPushButtonDot_clicked();
    void bvaOperations();
    void bvaMathOperations();
    void on_bvaPushButtonEquailty_clicked();
    void on_bvaPushButtonAC_clicked();
};
#endif // BVAMAINWINDOW_H
