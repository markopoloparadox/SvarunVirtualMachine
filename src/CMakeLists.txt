cmake_minimum_required (VERSION 2.6)
project (SvarunVirtualMachine)

set (
	Source
	main.cpp
	branch.cpp
	dataprocessing.cpp
	instruction.cpp
	memory.cpp
)
## Create project
add_executable( ${PROJECT_NAME} ${Source})

## Set flags for project
set_property(
	TARGET 
	${PROJECT_NAME} 
	PROPERTY 
	CXX_STANDARD 17
)

## Set include files for project
target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	../../SvarunCommon/include
	../include
	include
)