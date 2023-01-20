#include "adddialog.h"
#include "mainwindow.h"
#include "datavalidation.h"

#include <QtWidgets>

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent),
      nameText(new QLineEdit),
      addressText(new QTextEdit),
      phoneText(new QLineEdit),
      emailText(new QLineEdit)
{
    auto nameLabel = new QLabel(tr("Name"));
    auto addressLabel = new QLabel(tr("Address"));
    auto phoneLabel = new QLabel(tr("Phone"));
    auto emailLabel = new QLabel(tr("Email"));
    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    auto gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText, 0, 1);

    gLayout->addWidget(addressLabel, 1, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(addressText, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(phoneLabel, 2, 0);
    gLayout->addWidget(phoneText, 2, 1);

    gLayout->addWidget(emailLabel, 3, 0);
    gLayout->addWidget(emailText, 3, 1);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 4, 1, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Add a Contact"));
}

QString AddDialog::name() const
{
    return nameText->text();
}

QString AddDialog::address() const
{
    return addressText->toPlainText();
}

QString AddDialog::phone() const
{
    return phoneText->text();
}

QString AddDialog::email() const
{
    return emailText->text();
}

void AddDialog::editAddress(const QString &name, const QString &address, const QString &phone, const QString &email)
{
    nameText->setReadOnly(true);
    nameText->setText(name);
    addressText->setPlainText(address);
    if (is_valid_phone_number(phone.toStdString())) {
        phoneText->setText(phone);
    }
    if (is_valid_email(email.toStdString())) {
        emailText->setText(email);
    }
}
