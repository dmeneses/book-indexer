#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/bitmanipulation.o \
	${OBJECTDIR}/book-indexer.o \
	${OBJECTDIR}/converter.o \
	${OBJECTDIR}/filereader.o \
	${OBJECTDIR}/filewriter.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/book-indexer.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/book-indexer.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/book-indexer ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/bitmanipulation.o: bitmanipulation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/bitmanipulation.o bitmanipulation.cpp

${OBJECTDIR}/book-indexer.o: book-indexer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/book-indexer.o book-indexer.cpp

${OBJECTDIR}/converter.o: converter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/converter.o converter.cpp

${OBJECTDIR}/filereader.o: filereader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/filereader.o filereader.cpp

${OBJECTDIR}/filewriter.o: filewriter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/filewriter.o filewriter.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/consoletest.o ${TESTDIR}/tests/consoletestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/filereadertest.o ${TESTDIR}/tests/filereadertestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/filewritertest.o ${TESTDIR}/tests/filewritertestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/utf16convertertest.o ${TESTDIR}/tests/utf16convertertestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/utf8convertertest.o ${TESTDIR}/tests/utf8convertertestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/consoletest.o: tests/consoletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/consoletest.o tests/consoletest.cpp


${TESTDIR}/tests/consoletestrunner.o: tests/consoletestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/consoletestrunner.o tests/consoletestrunner.cpp


${TESTDIR}/tests/filereadertest.o: tests/filereadertest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/filereadertest.o tests/filereadertest.cpp


${TESTDIR}/tests/filereadertestrunner.o: tests/filereadertestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/filereadertestrunner.o tests/filereadertestrunner.cpp


${TESTDIR}/tests/filewritertest.o: tests/filewritertest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/filewritertest.o tests/filewritertest.cpp


${TESTDIR}/tests/filewritertestrunner.o: tests/filewritertestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/filewritertestrunner.o tests/filewritertestrunner.cpp


${TESTDIR}/tests/utf16convertertest.o: tests/utf16convertertest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/utf16convertertest.o tests/utf16convertertest.cpp


${TESTDIR}/tests/utf16convertertestrunner.o: tests/utf16convertertestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/utf16convertertestrunner.o tests/utf16convertertestrunner.cpp


${TESTDIR}/tests/utf8convertertest.o: tests/utf8convertertest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/utf8convertertest.o tests/utf8convertertest.cpp


${TESTDIR}/tests/utf8convertertestrunner.o: tests/utf8convertertestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/utf8convertertestrunner.o tests/utf8convertertestrunner.cpp


${OBJECTDIR}/bitmanipulation_nomain.o: ${OBJECTDIR}/bitmanipulation.o bitmanipulation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/bitmanipulation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/bitmanipulation_nomain.o bitmanipulation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/bitmanipulation.o ${OBJECTDIR}/bitmanipulation_nomain.o;\
	fi

${OBJECTDIR}/book-indexer_nomain.o: ${OBJECTDIR}/book-indexer.o book-indexer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/book-indexer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/book-indexer_nomain.o book-indexer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/book-indexer.o ${OBJECTDIR}/book-indexer_nomain.o;\
	fi

${OBJECTDIR}/converter_nomain.o: ${OBJECTDIR}/converter.o converter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/converter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/converter_nomain.o converter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/converter.o ${OBJECTDIR}/converter_nomain.o;\
	fi

${OBJECTDIR}/filereader_nomain.o: ${OBJECTDIR}/filereader.o filereader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filereader.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filereader_nomain.o filereader.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filereader.o ${OBJECTDIR}/filereader_nomain.o;\
	fi

${OBJECTDIR}/filewriter_nomain.o: ${OBJECTDIR}/filewriter.o filewriter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filewriter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filewriter_nomain.o filewriter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filewriter.o ${OBJECTDIR}/filewriter_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/book-indexer.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
