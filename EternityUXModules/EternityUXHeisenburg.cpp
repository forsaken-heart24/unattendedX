#include <iostream>
#include <string>
#include <shlwapi.h>
#include <windows.h>
#include <tlhelp32.h>
#include "EternityUXApplibrary.h"
#pragma comment(lib, "Shlwapi.lib")

void schtasks() {
    std::string command;
    const char *theseValuesWillGetChanged[] = {
        "Microsoft\\Windows\\Application Experience\\Microsoft Compatibility Appraiser",
        "Microsoft\\Windows\\Application Experience\\PcaPatchDbTask",
        "Microsoft\\Windows\\Application Experience\\ProgramDataUpdater",
        "Microsoft\\Windows\\Application Experience\\StartupAppTask",
        "Microsoft\\Windows\\Autochk\\Proxy",
        "Microsoft\\Windows\\Customer Experience Improvement Program\\Consolidator",
        "Microsoft\\Windows\\Customer Experience Improvement Program\\UsbCeip",
        "Microsoft\\Windows\\Defrag\\ScheduledDefrag",
        "Microsoft\\Windows\\Device Information\\Device",
        "Microsoft\\Windows\\Device Information\\Device User",
        "Microsoft\\Windows\\DiskCleanup\\SilentCleanup",
        "Microsoft\\Windows\\DiskDiagnostic\\Microsoft-Windows-DiskDiagnosticDataCollector",
        "Microsoft\\Windows\\DiskFootprint\\Diagnostics",
        "Microsoft\\Windows\\DiskFootprint\\StorageSense",
        "Microsoft\\Windows\\DUSM\\dusmtask",
        "Microsoft\\Windows\\EnterpriseMgmt\\MDMMaintenenceTask",
        "Microsoft\\Windows\\Feedback\\Siuf\\DmClient",
        "Microsoft\\Windows\\Feedback\\Siuf\\DmClientOnScenarioDownload",
        "Microsoft\\Windows\\Flighting\\FeatureConfig\\ReconcileFeatures",
        "Microsoft\\Windows\\Flighting\\FeatureConfig\\UsageDataFlushing",
        "Microsoft\\Windows\\Flighting\\FeatureConfig\\UsageDataReporting",
        "Microsoft\\Windows\\Flighting\\OneSettings\\RefreshCache",
        "Microsoft\\Windows\\Input\\LocalUserSyncDataAvailable",
        "Microsoft\\Windows\\Input\\MouseSyncDataAvailable",
        "Microsoft\\Windows\\Input\\PenSyncDataAvailable",
        "Microsoft\\Windows\\Input\\TouchpadSyncDataAvailable",
        "Microsoft\\Windows\\International\\Synchronize Language Settings",
        "Microsoft\\Windows\\LanguageComponentsInstaller\\Installation",
        "Microsoft\\Windows\\LanguageComponentsInstaller\\ReconcileLanguageResources",
        "Microsoft\\Windows\\LanguageComponentsInstaller\\Uninstallation",
        "Microsoft\\Windows\\License Manager\\TempSignedLicenseExchange",
        "Microsoft\\Windows\\Management\\Provisioning\\Cellular",
        "Microsoft\\Windows\\Management\\Provisioning\\Logon",
        "Microsoft\\Windows\\Maintenance\\WinSAT",
        "Microsoft\\Windows\\Maps\\MapsToastTask",
        "Microsoft\\Windows\\Maps\\MapsUpdateTask",
        "Microsoft\\Windows\\Mobile Broadband Accounts\\MNO Metadata Parser",
        "Microsoft\\Windows\\MUI\\LPRemove",
        "Microsoft\\Windows\\NetTrace\\GatherNetworkInfo",
        "Microsoft\\Windows\\PI\\Sqm-Tasks",
        "Microsoft\\Windows\\Power Efficiency Diagnostics\\AnalyzeSystem",
        "Microsoft\\Windows\\PushToInstall\\Registration",
        "Microsoft\\Windows\\Ras\\MobilityManager",
        "Microsoft\\Windows\\RecoveryEnvironment\\VerifyWinRE",
        "Microsoft\\Windows\\RemoteAssistance\\RemoteAssistanceTask",
        "Microsoft\\Windows\\RetailDemo\\CleanupOfflineContent",
        "Microsoft\\Windows\\Servicing\\StartComponentCleanup",
        "Microsoft\\Windows\\SettingSync\\NetworkStateChangeTask",
        "Microsoft\\Windows\\Setup\\SetupCleanupTask",
        "Microsoft\\Windows\\Setup\\SnapshotCleanupTask",
        "Microsoft\\Windows\\SpacePort\\SpaceAgentTask",
        "Microsoft\\Windows\\SpacePort\\SpaceManagerTask",
        "Microsoft\\Windows\\Speech\\SpeechModelDownloadTask",
        "Microsoft\\Windows\\Storage Tiers Management\\Storage Tiers Management Initialization",
        "Microsoft\\Windows\\Sysmain\\ResPriStaticDbSync",
        "Microsoft\\Windows\\Sysmain\\WsSwapAssessmentTask",
        "Microsoft\\Windows\\Task Manager\\Interactive",
        "Microsoft\\Windows\\TPM\\Tpm-HASCertRetr",
        "Microsoft\\Windows\\TPM\\Tpm-Maintenance",
        "Microsoft\\Windows\\UPnP\\UPnPHostConfig",
        "Microsoft\\Windows\\User Profile Service\\HiveUploadTask",
        "Microsoft\\Windows\\WDI\\ResolutionHost",
        "Microsoft\\Windows\\Windows Filtering Platform\\BfeOnServiceStartTypeChange",
        "Microsoft\\Windows\\WOF\\WIM-Hash-Management",
        "Microsoft\\Windows\\WOF\\WIM-Hash-Validation",
        "Microsoft\\Windows\\Work Folders\\Work Folders Logon Synchronization",
        "Microsoft\\Windows\\Work Folders\\Work Folders Maintenance Work",
        "Microsoft\\Windows\\Workplace Join\\Automatic-Device-Join",
        "Microsoft\\Windows\\WwanSvc\\NotificationTask",
        "Microsoft\\Windows\\WwanSvc\\OobeDiscovery",
        "Microsoft\\Windows\\Application Experience\\StartupAppTask",
        "Microsoft\\Windows\\DiskDiagnostic\\Microsoft-Windows-DiskDiagnosticDataCollector",
        "Microsoft\\Windows\\DiskDiagnostic\\Microsoft-Windows-DiskDiagnosticResolver",
        "Microsoft\\Windows\\Power Efficiency Diagnostics\\AnalyzeSystem",
        "Microsoft\\Windows\\Customer Experience Improvement Program\\Consolidator",
        "Microsoft\\Windows\\Customer Experience Improvement Program\\BthSQM",
        "Microsoft\\Windows\\Customer Experience Improvement Program\\KernelCeipTask",
        "Microsoft\\Windows\\Customer Experience Improvement Program\\UsbCeip",
        "Microsoft\\Windows\\Customer Experience Improvement Program\\Uploader",
        "Microsoft\\Windows\\Application Experience\\Microsoft Compatibility Appraiser",
        "Microsoft\\Windows\\Application Experience\\ProgramDataUpdater",
        "Microsoft\\Windows\\Shell\\FamilySafetyMonitor",
        "Microsoft\\Windows\\Shell\\FamilySafetyRefresh",
        "Microsoft\\Windows\\Shell\\FamilySafetyUpload"
    };
    const char *theseValuesMightGetCooked[] = {
        "\\Microsoft\\Windows\\DiskDiagnostic\\Microsoft-Windows-DiskDiagnosticDataCollector",
        "\\Microsoft\\Windows\\DiskDiagnostic\\Microsoft-Windows-DiskDiagnosticResolver",
        "\\Microsoft\\Windows\\Power Efficiency Diagnostics\\AnalyzeSystem",
        "\\Microsoft\\Windows\\Customer Experience Improvement Program\\Consolidator",
        "\\Microsoft\\Windows\\Customer Experience Improvement Program\\BthSQM",
        "\\Microsoft\\Windows\\Customer Experience Improvement Program\\KernelCeipTask",
        "\\Microsoft\\Windows\\Customer Experience Improvement Program\\UsbCeip",
        "\\Microsoft\\Windows\\Customer Experience Improvement Program\\Uploader",
        "\\Microsoft\\Windows\\Application Experience\\Microsoft Compatibility Appraiser",
        "\\Microsoft\\Windows\\Application Experience\\ProgramDataUpdater",
        "\\Microsoft\\Windows\\Application Experience\\StartupAppTask",
        "\\Microsoft\\Windows\\Shell\\FamilySafetyMonitor",
        "\\Microsoft\\Windows\\Shell\\FamilySafetyRefresh",
        "\\Microsoft\\Windows\\Shell\\FamilySafetyUpload",
        "\\Microsoft\\Windows\\Maintenance\\WinSAT"
    };
    for (int i = 0; i < sizeof(theseValuesWillGetChanged) / sizeof(theseValuesWillGetChanged[0]); i++) {
        if(is_debug) {
            command = "echo schtasks /Change /TN " + std::string(theseValuesWillGetChanged[i]) + " /Disable";
        }
        else {
            command = "schtasks /Change /TN " + std::string(theseValuesWillGetChanged[i]) + " /Disable";
        }
        system(command.c_str());
    }
    for (int i = 0; i < sizeof(theseValuesMightGetCooked) / sizeof(theseValuesMightGetCooked[0]); i++) {
        if(is_debug) {
            command = "echo schtasks /end /tn " + std::string(theseValuesMightGetCooked[i]);
        }
        else {
            command = "schtasks /end /tn " + std::string(theseValuesMightGetCooked[i]);
        }
        system(command.c_str());
    }
}

void touchRegistry() {
    std::string variableZero;
    std::string variableOne;
    std::string variableTwo;
    std::string variableThree;
    const char *modTheseKeyValues[] = {
        "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\appDiagnostics /F /V Value /T reg_SZ /d Deny",
        "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\appointments /F /V Value /T reg_SZ /d Deny",
        "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\email /F /V Value /T reg_SZ /d Deny",
        "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\phoneCall /F /V Value /T reg_SZ /d Deny",
        "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\userDataTasks /F /V Value /T reg_SZ /d Deny",
        "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\chat /F /V Value /T reg_SZ /d Deny",
        "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\contacts /F /V Value /T reg_SZ /d Deny",
        "HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\Messaging /F /V AllowMessageSync /T reg_DWORD /d 0",
        "HKCU\\Software\\Microsoft\\Office\\Common\\ClientTelemetry /v DisableTelemetry /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Common /v sendcustomerdata /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Common\\Feedback /v enabled /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Common\\Feedback /v includescreenshot /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Outlook\\Options\\Mail /v EnableLogging /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Word\\Options /v EnableLogging /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\Common\\ClientTelemetry /v SendTelemetry /t reg_DWORD /d 3 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Common /v qmenable /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Common /v updatereliabilitydata /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Common\\General /v shownfirstrunoptin /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Common\\General /v skydrivesigninoption /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Common\\ptwatson /v ptwoptin /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\Firstrun /v disablemovie /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM /v Enablelogging /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM /v EnableUpload /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM /v EnableFileObfuscation /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedapplications /v accesssolution /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedapplications /v olksolution /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedapplications /v onenotesolution /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedapplications /v pptsolution /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedapplications /v projectsolution /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedapplications /v publishersolution /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedapplications /v visiosolution /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedapplications /v wdsolution /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedapplications /v xlsolution /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedsolutiontypes /v agave /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedsolutiontypes /v appaddins /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedsolutiontypes /v comaddins /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedsolutiontypes /v documentfiles /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Office\\16.0\\OSM\\preventedsolutiontypes /v templatefiles /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Microsoft\\FTH /v Enabled /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\System /v EnableSmartScreen /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer /v SmartScreenEnabled /t reg_SZ /d Off /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\activity /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\appDiagnostics /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\appointments /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\bluetoothSync /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\broadFileSystemAccess /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\chat /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\contacts /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\documentsLibrary /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\gazeInput /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\microphone /v Value /t reg_SZ /d Allow /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\microphone\\Microsoft.Win32WebViewHost_cw5n1h2txyewy /v Value /t reg_SZ /d Prompt /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\phoneCall /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\phoneCallHistory /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\picturesLibrary /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\radios /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\userNotificationListener /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\videosLibrary /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v PreInstalledAppsEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SilentInstalledAppsEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v OemPreInstalledAppsEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v ContentDeliveryAllowed /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContentEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v PreInstalledAppsEverEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SystemPaneSuggestionsEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-338388Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-314559Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v ContentDeliveryUninstallEnabled /t reg_DWORD /d 0 /f"
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\SettingSync\\Groups\\StartLayout /v Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\SettingSync\\Groups\\Windows /v Enabled /t reg_DWORD /d 0 /f",
        "Auditpol /set /subcategory:Filtering Platform Connection /success:disable /failure:enable",
        "HKLM\\System\\CurrentControlSet\\Control\\WMI\\Autologger\\AutoLogger-Diagtrack-Listener /v Start /t reg_DWORD /d 0 /f",
        "HKLM\\System\\CurrentControlSet\\Control\\WMI\\Autologger\\DiagLog /v Start /t reg_DWORD /d 0 /f",
        "HKLM\\System\\CurrentControlSet\\Control\\WMI\\Autologger\\Diagtrack-Listener /v Start /t reg_DWORD /d 0 /f",
        "HKLM\\System\\CurrentControlSet\\Control\\WMI\\Autologger\\WiFiSession /v Start /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\IE /v CEIPEnable /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\IE /v SqmLoggerRunning /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\Reliability /v CEIPEnable /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\Reliability /v SqmLoggerRunning /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\Windows /v CEIPEnable /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\Windows /v DisableOptinExperience /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\Windows /v SqmLoggerRunning /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\AppV\\CEIP /v CEIPEnable /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Messenger\\Client /v CEIP /t reg_DWORD /d 2 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\SQMClient\\Windows /v CEIPEnable /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Policies\\Microsoft\\Internet Explorer\\SQM /v DisableCustomerImprovementProgram /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppCompat /v DisablePCA /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v DisableInventory /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v AITEnable /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v DisableUAR /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v VDMDisallowed /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v DisableEngine /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v DisableWizard /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v DisablePCA /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v SbEnable /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\WINEVT\\Channels\\Microsoft-Windows-Application-Experience/Steps-Recorder /v Enabled /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Policies\\Microsoft\\DeviceHealthAttestationService /v DisableSendGenericDriverNotFoundToWER /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DeviceInstall\\Settings /v DisableSendGenericDriverNotFoundToWER /t reg_DWORD /d 1 /f",
        "HKLM\\SYSTEM\\DriverDatabase\\Policies\\Settings /v DisableSendGenericDriverNotFoundToWER /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Policies\\Microsoft\\Windows\\CloudContent /v ConfigureWindowsSpotlight /t reg_DWORD /d 2 /f",
        "HKCU\\Software\\Policies\\Microsoft\\Windows\\CloudContent /v DisableThirdPartySuggestions /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Policies\\Microsoft\\Windows\\CloudContent /v DisableWindowsSpotlightFeatures /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\CloudContent /v DisableWindowsConsumerFeatures /t reg_DWORD /d 1 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v ContentDeliveryAllowed /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v FeatureManagementEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v OemPreInstalledAppsEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v PreInstalledAppsEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v PreInstalledAppsEverEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v RemediationRequired /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SilentInstalledAppsEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SoftLandingEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\UserProfileEngagement /v ScoobeSystemSettingEnabled /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v AllowOnlineTips /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Policies\\Microsoft\\PushToInstall /v DisablePushToInstall /t reg_DWORD /d 1 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SystemPaneSuggestionsEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-310093Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-338388Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-338389Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-353698Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-338387Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-338393Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-353694Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-353696Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-314563Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SubscribedContent-314559Enabled /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Device Metadata /v PreventDeviceMetadataFromNetwork /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\DataCollection /v AllowTelemetry /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\InputPersonalization /v RestrictImplicitInkCollection /t reg_DWORD /d 1 /f",
        "HKCU\\SOFTWARE\\Microsoft\\InputPersonalization /v RestrictImplicitTextCollection /t reg_DWORD /d 1 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Sensor\\Permissions\\{BFA794E4-F964-4FDB-90F6-51056BFE4B44} /v SensorPermissionState /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Sensor\\Overrides\\{BFA794E4-F964-4FDB-90F6-51056BFE4B44} /v SensorPermissionState /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\WUDF /v LogEnable /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\WUDF /v LogLevel /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection /v AllowTelemetry /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection /v DoNotShowFeedbackNotifications /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection /v AllowCommercialDataPipeline /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection /v AllowDeviceNameInTelemetry /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection /v LimitEnhancedDiagnosticDataWindowsAnalytics /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection /v MicrosoftEdgeDataOptIn /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Siuf\\Rules /v NumberOfSIUFInPeriod /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Siuf\\Rules /v PeriodInNanoSeconds /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Policies\\Microsoft\\Assistance\\Client\\1.0 /v NoExplicitFeedback /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Assistance\\Client\\1.0 /v NoActiveHelp /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v DisableInventory /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v AITEnable /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AppCompat /v DisableUAR /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\TabletPC /v PreventHandwritingDataSharing /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\TabletPC /v DoSvc /t reg_DWORD /d 3 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\LocationAndSensors /v DisableLocation /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\LocationAndSensors /v DisableLocationScripting /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\LocationAndSensors /v DisableSensors /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\LocationAndSensors /v DisableWindowsLocationProvider /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\DeviceHealthAttestationService /v DisableSendGenericDriverNotFoundToWER /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DeviceInstall\\Settings /v DisableSendGenericDriverNotFoundToWER /t reg_DWORD /d 1 /f",
        "HKLM\\SYSTEM\\DriverDatabase\\Policies\\Settings /v DisableSendGenericDriverNotFoundToWER /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\System /v PublishUserActivities /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\System /v EnableActivityFeed /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\System /v UploadUserActivities /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\SQMClient\\Windows /v CEIPEnable /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\Reliability /v CEIPEnable /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\Reliability /v SqmLoggerRunning /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\Windows /v CEIPEnable /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\Windows /v DisableOptinExperience /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\Windows /v SqmLoggerRunning /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\SQMClient\\IE /v SqmLoggerRunning /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\HandwritingErrorReports /v PreventHandwritingErrorReports /t reg_DWORD /d 1 /f",
        "HKCU\\SOFTWARE\\Microsoft\\MediaPlayer\\Preferences /v UsageTracking /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\CloudContent /v DisableSoftLanding /t reg_DWORD /d 0 /f"
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Peernet /v Disabled /t reg_DWORD /d 0 /f"
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\DeliveryOptimization\\Config /v DODownloadMode /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\PolicyManager\\default\\WiFi\\AllowWiFiHotSpotReporting /v value /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\InputPersonalization\\TrainedDataStore /v HarvestContacts /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AdvertisingInfo /v Enabled /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AdvertisingInfo /v DisabledByGroupPolicy /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\MRT /v DontOfferThroughWUAU /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Biometrics /v Enabled /t reg_DWORD /d 0 /f",
        "HKLM\\SYSTEM\\CurrentControlSet\\Services\\dmwappushservice /v Start /t reg_DWORD /d 4 /f",
        "HKLM\\SYSTEM\\DriverDatabase\\Policies\\Settings /v DisableSendGenericDriverNotFoundToWER /t reg_DWORD /d 1 /f",
        "HKCU\\Control Panel\\International\\User Profile /v HttpAcceptLanguageOptOut /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search /v AllowCortana /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search /v AllowCloudSearch /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search /v AllowCortanaAboveLock /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search /v AllowSearchToUseLocation /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search /v ConnectedSearchUseWeb /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search /v ConnectedSearchUseWebOverMeteredConnections /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search /v DisableWebSearch /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection /v DoNotShowFeedbackNotifications /t reg_DWORD /d 1 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Siuf\\Rules /v NumberOfSIUFInPeriod /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Siuf\\Rules /v PeriodInNanoSeconds /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Policies\\Microsoft\\Assistance\\Client\\1.0 /v NoExplicitFeedback /t reg_DWORD /d 1 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Assistance\\Client\\1.0\\Settings /v ImplicitFeedback /t reg_DWORD /d 0 /f",
        "HKCU\\Control Panel\\International\\User Profile /v HttpAcceptLanguageOptOut /t reg_DWORD /d 1 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AdvertisingInfo /v Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AppHost /v EnableWebContentEvaluation /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\Windows Error Reporting /v DontShowUI /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Windows\\Windows Error Reporting /v Disabled /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Windows\\Windows Error Reporting /v DontSendadditionalData /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Windows\\Windows Error Reporting /v LoggingDisabled /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Windows\\Windows Error Reporting\\Consent /v DefaultConsent /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Windows\\Windows Error Reporting\\Consent /v DefaultOverrideBehavior /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\Windows Error Reporting /v DontShowUI /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\PCHealth\\ErrorReporting /v DoReport /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\AdvertisingInfo /v DisabledByGroupPolicy /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\HandwritingErrorReports /v PreventHandwritingErrorReports /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\TabletPC /v PreventHandwritingDataSharing /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting /v AutoApproveOSDumps /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting /v Disabled /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting /v DontSendadditionalData /t reg_DWORD /d 1 /f",
        "HKLM\\SYSTEM\\CurrentControlSet\\Services\\W3SVC /v Start /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Microsoft\\PCHealth\\ErrorReporting /v ShowUI /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\FTH /v Enabled /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Google\\Chrome /v StartupBoostEnabled /t reg_DWORD /d 0 /f"
        "HKLM\\SOFTWARE\\Policies\\Google\\Chrome /v BackgroundModeEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\DWM /v UseDpiScaling /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Multimedia\\Audio /v UserDuckingPreference /t reg_DWORD /d 3 /f",
        "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Authentication\\LogonUI\\BootAnimation /v DisableStartupSound /t reg_DWORD /d 1 /f",
        "HKCU\\Control Panel\\Mouse /v MouseSpeed /t reg_SZ /d 0 /f",
        "HKCU\\Control Panel\\Mouse /v MouseThreshold1 /t reg_SZ /d 0 /f",
        "HKCU\\Control Panel\\Mouse /v MouseThreshold2 /t reg_SZ /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v ctfmon /t reg_SZ /d C:\\Windows\\System32\\ctfmon.exe /f",
        "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\VideoSettings /v VideoQualityOnBattery /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced /v IconsOnly /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced /v ListviewShadow /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection /v AllowTelemetry /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\DataCollection /v AllowTelemetry /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection /v AllowDeviceNameInTelemetry /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Policies\\Microsoft\\Windows\\safer\\codeidentifiers /v authenticodeenabled /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Policies\\Microsoft\\Windows\\Windows Error Reporting /v DontSendadditionalData /t reg_DWORD /d 1 /f",
        "HKLM\\Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Policies\\DataCollection /v AllowTelemetry /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Speech_OneCore\\Settings\\OnlineSpeechPrivacy /v HasAccepted /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Personalization\\Settings /v AcceptedPrivacyPolicy /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\InputPersonalization /v RestrictImplicitInkCollection /t reg_DWORD /d 1 /f",
        "HKCU\\SOFTWARE\\Microsoft\\InputPersonalization /v RestrictImplicitTextCollection /t reg_DWORD /d 1 /f",
        "HKCU\\SOFTWARE\\Microsoft\\InputPersonalization\\TrainedDataStore /v HarvestContacts /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DataCollection /v AllowTelemetry /t reg_DWORD /d 0 /f",
        "HKU\\S-1-5-20\\Software\\Microsoft\\Windows\\CurrentVersion\\DeliveryOptimization\\Settings /v DownloadMode /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\PushNotifications /v ToastEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings /v NOC_GLOBAL_SETTING_ALLOW_NOTIFICATION_SOUND /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings /v NOC_GLOBAL_SETTING_ALLOW_CRITICAL_TOASTS_ABOVE_LOCK /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings\\QuietHours /v Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings\\windows.immersivecontrolpanel_cw5n1h2txyewy!microsoft.windows.immersivecontrolpanel /v Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings\\Windows.SystemToast.AutoPlay /v Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings\\Windows.SystemToast.LowDisk /v Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings\\Windows.SystemToast.Print.Notification /v Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings\\Windows.SystemToast.SecurityAndMaintenance /v Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Notifications\\Settings\\Windows.SystemToast.WiFiNetworkManager /v Enabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Policies\\Microsoft\\Windows\\Explorer /v DisableNotificationCenter /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Feeds /v EnableFeeds /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft /v AllowNewsAndInterests /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\System /v EnableActivityFeed /t reg_DWORD /d 0 /f",
        "HKCU\\Control Panel\\International\\User Profile /v HttpAcceptLanguageOptOut /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\AdvertisingInfo /v Enabled /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Policies\\Microsoft\\Windows\\System /v EnableActivityFeed /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced /v DisallowShaking /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced /v EnableBalloonTips /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced /v ShowSyncProviderNotifications /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\userNotificationListener /v Value /t reg_SZ /d Deny /f",
        "HKLM\\Software\\Policies\\Microsoft\\Windows\\AdvertisingInfo /v DisabledByGroupPolicy /t reg_DWORD /d 1 /f",
        "HKCU\\Control Panel\\International\\User Profile /v HttpAcceptLanguageOptOut /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\DriverSearching /v SearchOrderConfig /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Device Metadata /v PreventDeviceMetadataFromNetwork /t reg_DWORD /d 1 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU /v NoAutoUpdate /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Windows\\DWM /v EnableAeroPeek /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\location /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\appDiagnostics /v Value /t reg_SZ /d Deny /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\userAccountInformation /v Value /t reg_SZ /d Deny /f",
        "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SilentInstalledAppsEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SystemPaneSuggestionsEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v SoftLandingEnabled /t reg_DWORD /d 0 /f",
        "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager /v RotatingLockScreenEnabled /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\System /v PublishUserActivities /t reg_DWORD /d 0 /f",
        "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\System /v UploadUserActivities /t reg_DWORD /d 0 /f",
        "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\BackgroundAccessApplications /v GlobalUserDisabled /t reg_DWORD /d 1 /f",
        "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Search /v BackgroundAppGlobalToggle /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\DeliveryOptimization\\Config /v DownloadMode /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Microsoft\\Windows\\Windows Error Reporting /v Disabled /t reg_DWORD /d 1 /f",
        "HKLM\\Software\\Microsoft\\Windows\\Windows Error Reporting /v DontSendadditionalData /t reg_DWORD /d 1 /f",
        "HKLM\\Software\\Microsoft\\Windows\\Windows Error Reporting /v DontShowUI /t reg_DWORD /d 1 /f",
        "HKLM\\Software\\Microsoft\\Windows\\Windows Error Reporting /v LoggingDisabled /t reg_DWORD /d 1 /f",
        "HKLM\\Software\\Microsoft\\Windows\\Windows Error Reporting\\Consent /v DefaultConsent /t reg_DWORD /d 0 /f",
        "HKLM\\Software\\Microsoft\\Windows\\Windows Error Reporting\\Consent /v DefaultOverrideBehavior /t reg_DWORD /d 1 /f"
    };
    const char *deleteTheseKeyValues[] = {
        "HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule\\TaskCache\\Tree\\MicrosoftEdgeUpdateTaskMachineCore",
        "HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule\\TaskCache\\Tree\\MicrosoftEdgeUpdateTaskMachineUA /f"
    };
    const char *pCIELatencyTweaker[] = {    
        "HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000 /v D3PCLatency /t REG_DWORD /d 1 /f",
        "HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000 /v F1TransitionLatency /t REG_DWORD /d 1 /f",
        "HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000 /v LOWLATENCY /t REG_DWORD /d 1 /f",
        "HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000 /v PciLatencyTimerControl /t REG_DWORD /d 20 /f",
        "HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000 /v RMDeepL1EntryLatencyUsec /t REG_DWORD /d 1 /f"
    };
    const char *uSBLatencyTweaker[] = { 
        "HKLM\\SYSTEM\\CurrentControlSet\\Enum\\%%a\\Device Parameters /v SelectiveSuspendOn /t REG_DWORD /d 0 /f",
        "HKLM\\SYSTEM\\CurrentControlSet\\Enum\\%%a\\Device Parameters /v SelectiveSuspendEnabled /t REG_BINARY /d 00 /f",
        "HKLM\\SYSTEM\\CurrentControlSet\\Enum\\%%a\\Device Parameters\\WDF /v IdleInWorkingState /t REG_DWORD /d 0 /f"
    };
    for(int i = 0; i < sizeof(pCIELatencyTweaker) / sizeof(pCIELatencyTweaker[0]); i++) {
        if(is_debug) {
            variableTwo = "echo reg add " + std::string(pCIELatencyTweaker[i]);
        }
        else {
            variableTwo = "reg add " + std::string(pCIELatencyTweaker[i]);
        }
        system(variableTwo.c_str());
    }
    for (int i = 0; i < sizeof(modTheseKeyValues) / sizeof(modTheseKeyValues[0]); i++) {
        if(is_debug) {
            variableZero = "echo reg add " + std::string(modTheseKeyValues[i]);
        }
        else {
            variableZero = "reg add " + std::string(modTheseKeyValues[i]);
        }
        system(variableZero.c_str());
    }
    for (int i = 0; i < sizeof(deleteTheseKeyValues) / sizeof(deleteTheseKeyValues[0]); i++) {
        if(is_debug) {
            variableOne = "echo reg delete " + std::string(deleteTheseKeyValues[i]);
        }
        else {
            variableOne = "reg delete " + std::string(deleteTheseKeyValues[i]); 
        }
        system(variableOne.c_str());
    }
}

// Define if whether this application build will run on init or desktop
// we should have to do it to get things working but we can use any value except 0 to 
// get the non-gui elements to work.
// This is the entry point for a GUI-based Windows application built using EternityUXApplibrary.h
int DoiHaveGUIElementSupport = 0;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    if(!isAdmin()) 
        WindowsMessageToastBox("Please run this application with administrator privilages!");
        exit(1);

    WindowsMessageToastBox("Search these up in google or ask ChatGPT if you don't know anything");
    if(WindowsMessageQuestionBox("Do you want to tweak the Task Schedular?")) {
        schtasks();
    }
    if(WindowsMessageQuestionBox("Do you want to tweak the System Registry?")) {
        touchRegistry();
    }
    WindowsMessageToastBox("Thanks for using ExternityUX :3");
}