AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = cear
cear_SOURCES = \
	Config.cc \
	Server.cc \
	Main.cc

cear_CPPFLAGS =  \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(CATA_CPPFLAGS) \
		$(AIR_CPPFLAGS)

cear_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(CATA_MD_LIBADD) \
	$(AIR_LIBADD)

cear_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = Config.hh \
	Log.hh \
	Server.hh

EXTRA_DIST = env.sh cear.cfg log.cfg

ceardir = $(bindir)
cear_DATA = $(EXTRA_DIST)

