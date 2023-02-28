project('Rahbar-e-Sukhan', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

qt5 = import('qt5')
qt5_dep = dependency('qt5', modules: ['Core', 'Gui', 'Quick'])
incdir = include_directories('../include')
# subdir('src')
# subdir('qml')
# subdir('Files')

headers = ['combination.hpp',  'fetch_dict.hpp',  'iosifovitch.hpp',  'Lafz.hpp',   'meters.hpp',  'Satr.hpp',           'utf8_string.hpp',
'dummy_class.hpp',  'input.hpp',       'Isqat.hpp',        'Meter.hpp',  'Satoor.hpp',  'utf8_iterator.hpp',  'utility.hpp']

sources = ['Lafz.cpp' ,'utf8_iterator.cpp' ,'Meter.cpp' ,'Satoor.cpp' ,'utf8_string.cpp' ,'input.cpp' ,'combination.cpp' ,'fetch_dict.cpp' ,'levenshtein.cpp' ,'Isqat.cpp' ,'dummy_class.cpp' ,'main.cpp'  ,'Satr.cpp']
# resources = qt5.compile_translations(qresource: 'qml.qrc')
exe = executable('rahbar_e_sukhan', sources, dependencies: qt5_dep, include_directories: incdir)

test('basic', exe)
