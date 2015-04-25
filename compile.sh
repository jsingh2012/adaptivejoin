cd udf
javac -classpath  pig.jar Hfilter.java
cd ..
jar -cf udf.jar udf
