## Tiger JSON/C++ Qt Based Mapping Library

Tiger depends on Qt Core module with MetaObject System enable to work.

Limitation:
 - Tiger uses the staticMetaObject of the Entity class, so it uses only the static created properties
 
### Usage

Simply put this line in your .pro qmake file: include(tiger.pri) 
And you'll able to use like a system header (<tiger>) 
