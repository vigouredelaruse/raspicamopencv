RASPICAMOPENCV

a c++ testbed for experimentation with opencv and live captured video

there are plenty of examples in python for working with opencv on the raspberry pi. this is not one of those.

instead presented here is a c++ implementation

many extant opencv examples lack a user interface, and deriving a performant implementation in the live video capture processing domain requires advanced programming not usually paired with such examples

this project attempts to correct that.

a minimal goal list is

demo opencv in c++
implement a reasonably modern looking ui, defined here as anything that goes beyond supplying command line switches
support my personal devops situation which is a heterogenous mix of operating systems and hardware
incorporate some best in show code from examples i will try my best to reference an extended goal list
support raspberry pi camera / opencv combinations
support ios
support macos / windows / linux
back all this with some youtube videos for the instructional aspect
the solution technology stack converged on

qtcreator for the ide
qt for the ui framework
enjoy
