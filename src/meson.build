inc = include_directories('include')
executable('snwbot', 'main.cpp', 'bot.cpp',
  include_directories : inc,
  dependencies : [boost_dep, hv_dep, nlohmann_json_dep, tomlplusplus_dep],
  install : true,
  install_dir : 'lib/snwbot')
install_symlink('snwbot', pointing_to : '../lib/snwbot/snwbot', install_dir : 'bin')
