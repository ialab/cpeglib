TARGET = myParser_java17

all: $(TARGET).class

$(TARGET).class: $(TARGET).java Mouse-1.9.jar
	javac -cp .:./Mouse-1.9.jar: $(TARGET).java

$(TARGET).java: Java.1.7.peg Mouse-1.9.jar
	java -cp .:./Mouse-1.9.jar: mouse.Generate -G ./Java.1.7.peg -P $(TARGET)

clean:
	$(RM) -f *.class
	$(RM) -f *.java


#.:./Mouse-1.9.jar: mouse.Generate -M -G ./Java.1.7.peg -P myParser_java17_M
# javac -cp .:./Mouse-1.9.jar: myParser_java17_M.java
