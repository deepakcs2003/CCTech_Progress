#include "ControlPanel.h"

QDoubleSpinBox* ControlPanel::makeSpinBox(double min, double max, double val, double step)
{
    QDoubleSpinBox* sb = new QDoubleSpinBox;
    sb->setRange(min, max);
    sb->setValue(val);
    sb->setSingleStep(step);
    sb->setDecimals(2);
    sb->setMinimumWidth(80);
    return sb;
}

ControlPanel::ControlPanel(QWidget* parent) : QWidget(parent)
{
    setFixedWidth(200);

    // --- Position Group ---
    QGroupBox* posGroup = new QGroupBox("Positions");
    QFormLayout* posForm = new QFormLayout;

    m_scale = makeSpinBox(0.01, 10.0, 1.0);
    m_x = makeSpinBox(-10, 10, 0.0);
    m_y = makeSpinBox(-10, 10, 0.0);
    m_z = makeSpinBox(-10, 10, 0.0);

    posForm->addRow("Scale:", m_scale);
    posForm->addRow("X:", m_x);
    posForm->addRow("Y:", m_y);
    posForm->addRow("Z:", m_z);
    posGroup->setLayout(posForm);

    // --- Rotation Group ---
    QGroupBox* rotGroup = new QGroupBox("Rotations");
    QFormLayout* rotForm = new QFormLayout;

    m_rx = makeSpinBox(-360, 360, 0.0, 1.0);
    m_ry = makeSpinBox(-360, 360, 0.0, 1.0);
    m_rz = makeSpinBox(-360, 360, 0.0, 1.0);

    rotForm->addRow("RX:", m_rx);
    rotForm->addRow("RY:", m_ry);
    rotForm->addRow("RZ:", m_rz);
    rotGroup->setLayout(rotForm);

    // --- Radius Group ---
    QGroupBox* radGroup = new QGroupBox("Sphere");
    QFormLayout* radForm = new QFormLayout;
    m_radius = makeSpinBox(0.01, 5.0, 0.5);
    radForm->addRow("Radius:", m_radius);
    radGroup->setLayout(radForm);

    // --- Main Layout ---
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(radGroup);
    layout->addWidget(posGroup);
    layout->addWidget(rotGroup);
    layout->addStretch();
    setLayout(layout);

    connectAll();
}

void ControlPanel::connectAll()
{
    // Koi bhi spinbox change hone par signal emit karo
    auto notify = [this]() {
        emit paramsChanged(getParams());
        };

    connect(m_radius, &QDoubleSpinBox::valueChanged, this, notify);
    connect(m_scale, &QDoubleSpinBox::valueChanged, this, notify);
    connect(m_x, &QDoubleSpinBox::valueChanged, this, notify);
    connect(m_y, &QDoubleSpinBox::valueChanged, this, notify);
    connect(m_z, &QDoubleSpinBox::valueChanged, this, notify);
    connect(m_rx, &QDoubleSpinBox::valueChanged, this, notify);
    connect(m_ry, &QDoubleSpinBox::valueChanged, this, notify);
    connect(m_rz, &QDoubleSpinBox::valueChanged, this, notify);
}

SphereParams ControlPanel::getParams() const
{
    SphereParams p;
    p.radius = static_cast<float>(m_radius->value());
    p.scale = static_cast<float>(m_scale->value());
    p.x = static_cast<float>(m_x->value());
    p.y = static_cast<float>(m_y->value());
    p.z = static_cast<float>(m_z->value());
    p.rx = static_cast<float>(m_rx->value());
    p.ry = static_cast<float>(m_ry->value());
    p.rz = static_cast<float>(m_rz->value());
    return p;
}