project('snwbot', 'cpp',
  default_options : ['cpp_std=c++20'])

cpp = meson.get_compiler('cpp')

hv_dep = cpp.find_library('hv')
boost_dep = dependency('boost', modules : ['filesystem'])
nlohmann_json_dep = dependency('nlohmann_json')

subdir('include')
subdir('src')

subdir('plugins')
