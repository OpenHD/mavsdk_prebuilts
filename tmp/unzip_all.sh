#bin/bash


unzip_and_copy(){
	echo $1 
	echo $2
	
	unzip -o $1
	
	rm -rf build
	7z x $2
	
	mv build/* output
	
	rm -rf $2
	rm -rf build
}



rm -rf output
mkdir output

unzip_and_copy MAVSDK-android-arm.zip mavsdk-android-android-arm.7z

unzip_and_copy MAVSDK-android-x86.zip mavsdk-android-android-x86.7z

unzip_and_copy MAVSDK-android-x86_64.zip mavsdk-android-android-x86_64.7z

# is zipped / built differently, since it comes from a different builder. whatever
mkdir -p output/android-arm64/install
unzip MAVSDK-android-arm64.zip -d output/android-arm64/install/


