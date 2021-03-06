#ifndef BLECOMM_H
#define BLECOMM_H

#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QLowEnergyController>

#include <IToBoardComm.h>
#include <connector.h>

class BleComm : public IToBoardComm
{
    //成员变量
Q_OBJECT
QBluetoothDeviceDiscoveryAgent *discoveryAgent;
QLowEnergyController *bleController;
Connector *connector;
QLowEnergyService *m_Service;
bool m_foundHeartRateService;
//QBluetoothUuid serviceUuid;

// IShape interface
public:
    BleComm(Connector *connector);
    void init() override;
    void send(QByteArray arr) override;
    void closeComm() override;

private:
    void onFindBleDevice(const QBluetoothDeviceInfo &info);
    void onScanFinished();
    void onScanCanceled();
    void serviceDiscovered(const QBluetoothUuid &gatt);
    void discoveryFinished();
    void onBleConneErr(QLowEnergyController::Error newError);
    void deviceConnected();
    void deviceDisconnected();

    void SL_serviceStateChanged(QLowEnergyService::ServiceState newState);
    void SL_characteristicChanged(const QLowEnergyCharacteristic &info,const QByteArray &value);
    void SL_descriptorWritten(const QLowEnergyDescriptor &info,const QByteArray &value);
};






#endif // BLECOMM_H
