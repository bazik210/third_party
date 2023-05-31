project(bugtrap LANGUAGES CXX)

add_library(bugtrap SHARED
						# Dialogs
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/AboutDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/DescribeErrorDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/MachineInfoDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/MachineStateDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/MainDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/PreviewDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/SendMailDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/SimpleDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/TransferProgressDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/WaitDlg.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/AboutDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/DescribeErrorDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/MachineInfoDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/MachineStateDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/MainDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/PreviewDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/SendMailDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/SimpleDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/TransferProgressDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/WaitDlg.h"
						# Collections
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/ColHelper.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/StrHolder.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/Array.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/Buffer.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ColHelper.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/Hash.h"
						# MISSING
						#"${CMAKE_CURRENT_SOURCE_DIR}/InPlaceNew.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/InterfacePtr.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/List.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/SmartPtr.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/StrHolder.h"
						# Controls
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/AnimProgressBar.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/HexView.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/HyperLink.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/ImageView.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/LayoutManager.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/Splitter.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextView.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/WaitCursor.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/AnimProgressBar.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/HexView.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/HyperLink.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ImageView.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/LayoutManager.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/Splitter.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextView.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/WaitCursor.h"
						# System
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/CMapi.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/EnumProcess.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/LogFile.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/LogStream.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/ModuleImportTable.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/NetThunks.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/SymEngine.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/SymEngineNet.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextLogFile.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/ThemeXP.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlLogFile.cpp"
						# XML
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlReader.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlWriter.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlReader.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlWriter.h"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/CMapi.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/EnumProcess.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/LogFile.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/LogLink.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ModuleImportTable.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/NetThunks.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/SymEngine.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/SymEngineNet.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextLogFile.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ThemeXP.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlLogFile.h"
						# Main
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrap.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapNet.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapUI.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapUtils.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/ResManager.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/BTAtlWindow.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BTMfcWindow.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BTTrace.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrap.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapNet.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapUI.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapUtils.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ResManager.h"
						# Accessories
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/AssemblyInfo.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/Globals.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/stdafx.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/Globals.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/LeakWatcher.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/resource.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/stdafx.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/VersionInfo.h"
						# Resource Files
						"${CMAKE_CURRENT_SOURCE_DIR}/res/Bug.ico"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrap.rc"
						"${CMAKE_CURRENT_SOURCE_DIR}/res/CheckMark.bmp"
						"${CMAKE_CURRENT_SOURCE_DIR}/res/ImageToolbar.bmp"
						"${CMAKE_CURRENT_SOURCE_DIR}/res/SortArrows.bmp"
						"${CMAKE_CURRENT_SOURCE_DIR}/res/Upload.avi"
						# Streams
						# Source Files
						# MISSING
						#"${CMAKE_CURRENT_SOURCE_DIR}/ileStream.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/InputStream.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/MemStream.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/OutputStream.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/StrStream.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/Stream.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/StrStream.h"
						# Encodings
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/Encoding.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextFormat.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/Encoding.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextFormat.h"
						# ./
)

set_target_properties(bugtrap PROPERTIES FOLDER "engine/sdk/bugtrap")



#####################



add_library(bugtrapN SHARED
						# Dialogs
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/AboutDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/DescribeErrorDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/MachineInfoDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/MachineStateDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/MainDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/PreviewDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/SendMailDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/SimpleDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/TransferProgressDlg.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/WaitDlg.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/AboutDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/DescribeErrorDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/MachineInfoDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/MachineStateDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/MainDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/PreviewDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/SendMailDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/SimpleDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/TransferProgressDlg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/WaitDlg.h"
						# Collections
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/ColHelper.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/StrHolder.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/Array.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/Buffer.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ColHelper.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/Hash.h"
						# MISSING
						#"${CMAKE_CURRENT_SOURCE_DIR}/InPlaceNew.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/InterfacePtr.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/List.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/SmartPtr.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/StrHolder.h"
						# Controls
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/AnimProgressBar.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/HexView.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/HyperLink.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/ImageView.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/LayoutManager.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/Splitter.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextView.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/WaitCursor.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/AnimProgressBar.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/HexView.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/HyperLink.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ImageView.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/LayoutManager.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/Splitter.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextView.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/WaitCursor.h"
						# System
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/CMapi.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/EnumProcess.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/LogFile.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/LogStream.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/ModuleImportTable.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/NetThunks.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/SymEngine.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/SymEngineNet.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextLogFile.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/ThemeXP.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlLogFile.cpp"
						# XML
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlReader.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlWriter.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlReader.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlWriter.h"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/CMapi.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/EnumProcess.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/LogFile.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/LogLink.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ModuleImportTable.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/NetThunks.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/SymEngine.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/SymEngineNet.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextLogFile.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ThemeXP.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/XmlLogFile.h"
						# Main
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrap.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapNet.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapUI.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapUtils.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/ResManager.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/BTAtlWindow.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BTMfcWindow.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BTTrace.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrap.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapNet.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapUI.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrapUtils.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ResManager.h"
						# Accessories
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/AssemblyInfo.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/Globals.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/stdafx.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/Globals.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/LeakWatcher.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/resource.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/stdafx.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/VersionInfo.h"
						# Resource Files
						"${CMAKE_CURRENT_SOURCE_DIR}/res/Bug.ico"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrap.def"
						"${CMAKE_CURRENT_SOURCE_DIR}/BugTrap.rc"
						"${CMAKE_CURRENT_SOURCE_DIR}/res/CheckMark.bmp"
						"${CMAKE_CURRENT_SOURCE_DIR}/res/ImageToolbar.bmp"
						"${CMAKE_CURRENT_SOURCE_DIR}/res/SortArrows.bmp"
						"${CMAKE_CURRENT_SOURCE_DIR}/res/Upload.avi"
						# Streams
						# Source Files
						# MISSING
						#"${CMAKE_CURRENT_SOURCE_DIR}/ileStream.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/InputStream.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/MemStream.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/OutputStream.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/StrStream.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/Stream.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/StrStream.h"
						# Encodings
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/Encoding.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextFormat.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/Encoding.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/TextFormat.h"
						# ./
)

target_compile_definitions(bugtrapN PRIVATE
    _WINDOWS    
    _USRDLL
    BUGTRAP_EXPORT
    _UNICODE
)
target_link_directories(bugtrapN PRIVATE
    ${SOLUTION_DIR_INCLUDE_PATH}/binaries
)

set_target_properties(bugtrapN PROPERTIES FOLDER "engine/sdk/bugtrap")