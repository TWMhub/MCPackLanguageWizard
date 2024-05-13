#ifndef MCWIZARD_H
#define MCWIZARD_H

//libs
//standard libraries
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

//third-party libraries
#include "rapidjson/document.h"
#include "yaml-cpp/yaml.h"

//another headers
#include "BuildTypeEnum.h"
#include "TypeEnum.h"
#include "TargetInitEnum.h"
#include "ModeBuildEnum.h"
#include "AdditionalFuctions.h"
#include "TextLineClass.h"
#include "CompiledFileStruct.h"
#include "WizardClass.h"

//namespace
namespace fs = std::filesystem;
namespace depozit_wizard {}; 

#endif
