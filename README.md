![MCPackLanguageWizard](https://avatars.githubusercontent.com/u/150254116?s=200&v=4)

# MCPackLanguageWizard #
MCPackLanguageWizard is an enhanced and extended version of our previous library [SNBT-parser](https://github.com/TWMhub/SNBT-parser "SNBT-reader GitHub Page").
***

## Description ##
Unlike the previous version, MCPackLanguageWizard can work not only with quests from the FTB Quests mod, but also texts from other mods, links in kube js, and a few other minor details. You can find detailed information about this in the documentation below.
***

## Documentation ##

- Recommended namespace alias:
```cpp
namespace dw = depozit_wizard;
```
- Since the library works with all text strings in the std::wstring format, I've added simple conversion functions.
  > Note: sometimes you may need to use the .c_str() function for successful string conversion in these functions.
```cpp
dw::strToWstr(const std::string& in); //-> std::wstring()
dw::wstrToStr(const std::wstring& in); //-> std::wstring()
```
---
### auxiliary class TextLine ###
- this class stores: the original line, the translated line and the line number in the file.
- there are 3 ways to create one. Here are the 2 main ones:
```cpp
dw::TextLine(int, const std::wstring&);
dw::TextLine(int, const std::wstring&, const std::wstring&);
```
- there is also the 3rd way, but further you will need to initialise the class to a working state:
```cpp
dw::TextLine() classObject;
classObject.init(int, const std::wstring&);
classObject.init(int, const std::wstring&, const std::wstring&);
```
- after initialization, you can add a line with a translation, if you did not do it during initialization
```cpp
classObject.addLocaleLine(const std::wstring&);
```
- all the data you entered can be retrieved:
```cpp
classObject.getPos(); //-> int()
classObject.getOrigLine(); //-> std::wstring()
classObject.getLocaleLine(); //-> std::wstring()
```
- you can clear all data. the class will be the same as when using an empty constructor:
```cpp
classObject.clear();
```
- since the library is tailored to work with quests from the FTBQuest mod, there is a function to check for special characters. if the translation was lost special characters you will know:
```cpp
classObject.analysisErrors(); -> std::wstring (no errors found || space-delimited enumeration of lost special characters)
```
---
### main class Wizard ###
