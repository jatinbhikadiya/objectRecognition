CC = g++
CFLAGS = -c
WFLAGS = -Wall 
OPTS = -O0
OFLAGS =  -g2

#Boost Libs Go Here
BOOST_LIBS = -lboost_system  -lboost_filesystem  -lboost_program_options 

LFLAGS = -llapack -lm

EXECUTABLE = Assignment-4

#Opencv Includes Go here
OPENCV_PATH = /usr/local/OpenCV
#OPENCV_PATH = /s/chopin/l/grad/bhikadiy/OpenCV-2.3.2
#OPENCV_PATH = /s/parsons/h/proj/vision/usr/jatin/lib/Opencv-2.4.4
OPENCV_LIBS = -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_ts -lopencv_video -lopencv_nonfree
OPENCV_INCPATH = -I$(OPENCV_PATH)/include/
OPENCV_LIBPATH = -L$(OPENCV_PATH)/lib/ 

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))


SUBMIT_DIR = $(shell whoami)
BACKUP_DIR = $(shell date "+%b_%d_%Y_%I_%M")
BACKUP_REPO	= ./Backups
BACKUP_PATH = $(BACKUP_REPO)/$(BACKUP_DIR)

all:$(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(WFLAGS) $(OPTS) $(LFLAGS)  $(OPENCV_INCPATH) $(OPENCV_LIBPATH) $(OPENCV_LIBS) $(BOOST_LIBS) $^ -o $@   $(LFLAGS)

obj/%.o: src/%.cpp
	mkdir -p ./obj
	$(CC) $(CFLAGS) $(WFLAGS) $(OPENCV_INCPATH) $(OPTS) $(OFLAGS)  -c -o $@ $<  $(LFLAGS)



clean:
	rm -f $(OBJ_FILES)
	rm -f *.out
	rm -f *~
	rm -f $(EXECUTABLE) 
	
	
#Create a Backup directory with <Month>_<Date>_<Year>_<Hr>_<Min>_<Sec>.tar
backup: 
	mkdir -p $(BACKUP_REPO)
	mkdir -p $(BACKUP_PATH)
	mkdir -p $(BACKUP_PATH)/src
	cp -r ./src/*.h ./$(BACKUP_PATH)/src
	cp -r ./src/*.cpp ./$(BACKUP_PATH)/src
	cp Makefile $(BACKUP_PATH)/
	cp TestScript.sh $(BACKUP_PATH)/
	tar -zcvf $(BACKUP_REPO)/$(BACKUP_DIR).tar $(BACKUP_PATH)/
	rm -rf $(BACKUP_PATH)
