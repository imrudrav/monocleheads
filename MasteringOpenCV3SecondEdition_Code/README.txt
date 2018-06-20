Each chapter of the book is for a separate project. Therefore there are 7 projects for the 7 chapters (note that the 1st edition of the book also had a 9th chapter, only in the eBook).

You can run each project separately, they each contain a README.md text file describing how to build that project, using CMake in most cases, because CMake can be used with many compilers and many operating systems.

To build & run the projects for the book:
--------------------------------------------------------------------------------
- Install OpenCV (version 3.1.0 is recommended, whereas OpenCV 2 is only supported in the 1st edition of this book). eg: go to "http://opencv.org/", click on
  Downloads, download the latest OpenCV 3.1 version (including prebuilt library), and extract
  it to "C:\OpenCV" for Windows or "~/OpenCV" for Linux. In OpenCV v3.1.0, the
  prebuilt OpenCV library is in "C:\OpenCV\build" or "~/OpenCV/build", such as
  "C:\OpenCV\build\x64\vc9" for MS Visual Studio 2008 (or "vs10" folder for MS 
  Visual Studio 2010, or the "x86" parent folder for 32-bit Windows).

- Install all the source code of the book. eg: extract the code to
  "C:\MasteringOpenCV" for Windows or "~/MasteringOpenCV" for Linux.
  
- Install CMake v2.8 or later from "http://www.cmake.org/".