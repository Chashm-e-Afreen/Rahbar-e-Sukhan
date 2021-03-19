project('Rahbar-e-Sukhan', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

qt5 = import('qt5-quickcontrols')
qt5_dep = dependency('qt5-quickcontrols', modules: ['Core', 'Gui', 'Qt Quick', 'Qt Quick Layouts', 'Qt Quick Controls'])
incdir = include_directories('../include')
# subdir('src')
# subdir('qml')
# subdir('Files')

sources = ['Lafz.cpp' ,'utf8_iterator.cpp' ,'Meter.cpp' ,'Satoor.cpp' ,'utf8_string.cpp' ,'input.cpp' ,'combination.cpp' ,'fetch_dict.cpp' ,'levenshtein.cpp' ,'Isqat.cpp' ,'dummy_class.cpp' ,'main.cpp' ,'edlib.cpp' ,'Satr.cpp']
resources = qt5.compile_translations(qresource: 'qml.qrc')
exe = executable('rahbar_e_sukhan', sources, resources,  dependencies: qt5_dep)

test('basic', exe)
