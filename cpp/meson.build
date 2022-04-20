project('aoc-2021', 'cpp',
        default_options: ['default_library=static', 'cpp_std=c++2a']
        )

incdir = include_directories('src')

sources = files([
  './src/main.cpp',
  './src/day1/solve.cpp',
  './src/util/util.cpp'
  ])

executable('aoc', sources, include_directories : incdir)
