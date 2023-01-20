#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTextEdit;
class QLineEdit;
QT_END_NAMESPACE

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    AddDialog(QWidget *parent = nullptr);

    QString name() const;
    QString address() const;
    QString phone() const;
    QString email() const;

    void editAddress(const QString &name, const QString &address, const QString &phone, const QString &email);

private:
    QLineEdit *nameText;
    QTextEdit *addressText;
    QLineEdit *phoneText;
    QLineEdit *emailText;

};

#endif // ADDDIALOG_H
