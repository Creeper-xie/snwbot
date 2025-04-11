project('snwbot', 'cpp',
  default_options : ['cpp_std=c++20'])

cpp = meson.get_compiler('cpp')

if cpp.has_argument('-Wsuggest-override')
  add_project_arguments('-Wsuggest-override', language : 'cpp')
endif

hv_dep = cpp.find_library('hv')
boost_dep = dependency('boost', modules : ['filesystem'])
nlohmann_json_dep = dependency('nlohmann_json')
tomlplusplus_dep = dependency('tomlplusplus')

subdir('src')

subdir('plugins')
