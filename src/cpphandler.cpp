#include "cpphandler.h"

CppHandler::CppHandler(QObject *parent) : QObject(parent)
{
}

QString CppHandler::selectedValue() const
{
    return m_selectedValue;
}

void CppHandler::setSelectedValue(const QString &value)
{
    if (value != m_selectedValue) {
        m_selectedValue = value;
        emit selectedValueChanged();
    }
}
