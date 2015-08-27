##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=_SimpleTextUI
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Akash\Documents\Programming\_codelite\c++"
ProjectPath            := "C:\Users\Akash\Documents\Programming\_codelite\c++\_SimpleTextUI"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Akash
Date                   :=26/08/2015
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :="C:/Program Files (x86)/LLVM/bin/clang++.exe"
SharedObjectLinkerName :="C:/Program Files (x86)/LLVM/bin/clang++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="_SimpleTextUI.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include/c++ $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include/c++/mingw32 $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include/c++/backward $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include $(IncludeSwitch)c:/MinGW/include $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include-fixed $(IncludeSwitch)c:/MinGW/mingw32/include  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "C:/Program Files (x86)/LLVM/bin/llvm-ar.exe" rcu
CXX      := "C:/Program Files (x86)/LLVM/bin/clang++.exe"
CC       := "C:/Program Files (x86)/LLVM/bin/clang.exe"
CXXFLAGS := -std=c++11 -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files (x86)/LLVM/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/IOObj.cpp$(ObjectSuffix) $(IntermediateDirectory)/src__test.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_input.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Menu.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\Users\Akash\Documents\Programming\_codelite\c++/.build-debug"
	@echo rebuilt > "C:\Users\Akash\Documents\Programming\_codelite\c++/.build-debug/_SimpleTextUI"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/IOObj.cpp$(ObjectSuffix): IOObj.cpp $(IntermediateDirectory)/IOObj.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Akash/Documents/Programming/_codelite/c++/_SimpleTextUI/IOObj.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IOObj.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IOObj.cpp$(DependSuffix): IOObj.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IOObj.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IOObj.cpp$(DependSuffix) -MM "IOObj.cpp"

$(IntermediateDirectory)/IOObj.cpp$(PreprocessSuffix): IOObj.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IOObj.cpp$(PreprocessSuffix) "IOObj.cpp"

$(IntermediateDirectory)/src__test.cpp$(ObjectSuffix): src/_test.cpp $(IntermediateDirectory)/src__test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Akash/Documents/Programming/_codelite/c++/_SimpleTextUI/src/_test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src__test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src__test.cpp$(DependSuffix): src/_test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src__test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src__test.cpp$(DependSuffix) -MM "src/_test.cpp"

$(IntermediateDirectory)/src__test.cpp$(PreprocessSuffix): src/_test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src__test.cpp$(PreprocessSuffix) "src/_test.cpp"

$(IntermediateDirectory)/src_input.cpp$(ObjectSuffix): src/input.cpp $(IntermediateDirectory)/src_input.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Akash/Documents/Programming/_codelite/c++/_SimpleTextUI/src/input.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_input.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_input.cpp$(DependSuffix): src/input.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_input.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_input.cpp$(DependSuffix) -MM "src/input.cpp"

$(IntermediateDirectory)/src_input.cpp$(PreprocessSuffix): src/input.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_input.cpp$(PreprocessSuffix) "src/input.cpp"

$(IntermediateDirectory)/src_Menu.cpp$(ObjectSuffix): src/Menu.cpp $(IntermediateDirectory)/src_Menu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Akash/Documents/Programming/_codelite/c++/_SimpleTextUI/src/Menu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Menu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Menu.cpp$(DependSuffix): src/Menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Menu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Menu.cpp$(DependSuffix) -MM "src/Menu.cpp"

$(IntermediateDirectory)/src_Menu.cpp$(PreprocessSuffix): src/Menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Menu.cpp$(PreprocessSuffix) "src/Menu.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


