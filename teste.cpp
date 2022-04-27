#include <iostream>
#include <windows.h>

int main() {
	auto activeWindow = GetForegroundWindow();
	HMONITOR monitor = MonitorFromWindow(activeWindow, MONITOR_DEFAULTTONEAREST);
	
	MONITORINFOEX monitorInfoEx;
	monitorInfoEx.cbSize = sizeof(monitorInfoEx);
	GetMonitorInfo(monitor, &monitorInfoEx);
	auto cxLogical = monitorInfoEx.rcMonitor.right - monitorInfoEx.rcMonitor.left;
	auto cyLogical = monitorInfoEx.rcMonitor.bottom - monitorInfoEx.rcMonitor.top;

	std::cout << "cxLogical: " << cxLogical << std::endl;
	std::cout << "cyLogical: " << cyLogical << std::endl;

	DEVMODE devMode;
	devMode.dmSize = sizeof(devMode);
	devMode.dmDriverExtra = 0;
	EnumDisplaySettings(monitorInfoEx.szDevice, ENUM_CURRENT_SETTINGS, &devMode);
	auto cxPhysical = devMode.dmPelsWidth;
	auto cyPhysical = devMode.dmPelsHeight;

	std::cout << "cxPhysical: " << cxPhysical << std::endl;
	std::cout << "cyPhysical: " << cyPhysical << std::endl;

	auto horizontalScale = ((double) cxPhysical / (double) cxLogical);
	auto verticalScale = ((double) cyPhysical / (double) cyLogical);    

    std::cout << "==========================================================" << std::endl;
    std::cout << "Horizontal Scale: " << horizontalScale << std::endl;
    std::cout << "Vertical Scale: " << verticalScale << std::endl;
}