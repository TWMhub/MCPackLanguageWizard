#ifndef MCWIZARD_H
#define MCWIZARD_H

//libs
//std
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include <chrono>
#include <map>

//namespace
namespace fs = std::filesystem;
namespace depozit_wizard {};

//third-party libraries
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "yaml-cpp/yaml.h"	
#include "zip.h"

//another headers
#include "AdditionalFuctions.h"
#include "DataProcessorClass.h"
#include "FileHandlerClass.h"
#include "TextLineClass.h"
#include "CompiledFileStruct.h"
#include "WizardClass.h"


#endif
