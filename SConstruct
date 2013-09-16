#!/usr/bin/python
import os, os.path, sys
import SCons.Script, SCons.Environment

allobjs = []

srcDir     = 'src'
incDir     = 'include'
subsubDirs = [ '/AllTheBugs', '/engine' ]

allSrcDirs = [ srcDir + d for d in subsubDirs ]
allIncDirs = [ incDir + d for d in subsubDirs ]

variantDirs = [ os.path.join( '.build', d ) for d in allSrcDirs ]
consFiles   = [ os.path.join( d, 'SConscript' ) for d in allSrcDirs ]

env = SCons.Environment.Environment(
    CPPFLAGS = '-Wall -c -std=c++11',
    CPPPATH = allIncDirs + ['/usr/include/SDL2'],
    ENV = {'INCLUDE': os.environ['INCLUDE'], 
           'PATH' : os.environ['PATH']})

env.VariantDir( variantDirs, srcDir )

allobjs    += [ env.SConscript( f, exports=['env'] ) for f in consFiles ]
print(allobjs)


exe         = env.Program( 'AllTheBugs.x', allobjs, LIBS='SDL2' )
