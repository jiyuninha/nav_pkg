  
# 🚀 SCOUT 2.0 Navigation 
---

This package is a code that follows a waypoint-based global path for Scout 2.0. It performed path tracking based on the pure pursuit algorithm and PID steering angle control.


<br/><br/>

## **Prerequisites**
---
- LiDAR localization [**Fast Localization**](https://github.com/hwan0806/FAST-LOCALIZATION)
  - pcd data(submap) [**data**](https://drive.google.com/file/d/1uJNYgAl9EpmnVGMoPCPvhDYSY3XAQz-t/view?usp=sharing)
  
- [**scout package**](https://github.com/agilexrobotics/scout_ros)
- [**ugv_sdk**](https://github.com/westonrobot/ugv_sdk)

<br/><br/>

## **Sensors**
---
- Ouster 64ch 
<p align="center"><img src="./fig/mount.jpg"  width="400" height="600"/>


## **Updates**
---
[**scout_nav**](https://github.com/jiyuninha/nav_pkg_stanley) based on stanley method. This package will be updated continuously. 

<br/><br/>

## **Development Environment Setup**
---
- ROS noetic, ubuntu20.04

<br/>
<br/>

1. installation for scout 
```
mkdir scout_ws/src && cd scout_ws/src
catkin_init_workspace
git clone https://github.com/jiyuninha/nav_pkg.git
git clone https://github.com/westonrobot/ugv_sdk.git
git clone https://github.com/agilexrobotics/scout_ros.git
cd ~/scout_ws
catkin_make

```

2. installation for LiDAR localization
```
mkdir loc/src && cd loc/src
catkin_init_workspace
git clone https://github.com/ouster-lidar/ouster-ros.git
git clone https://github.com/hwan0806/FAST-LOCALIZATION.git
cd ~/loc 
catkin_make
```

3. first terminar
```
cd ~/loc
source devel/setup.bash
roslaunch ouster-ros sensor.launch
```
4. second terminar
```
cd ~/loc 
source devel/setup.bash
roslaunch fast_localization localization_ouster64.launch
```
5. third terminar
```
cd ~/scout_ws 
source devel/setup.bash
roscd scour_bringup 
cd scripts 
./bringup_can2usb.bash
cd ..
cd launch 
roslaunch scout_robot_base.launch
```
5. fourth terminar
```
cd ~/scout_ws
source devel/setup.bash
roslaunch nav_pkg nav.launch
```

<br/><br/>

## **Result and Video**
---
<p align="center"><img src="./fig/globalpath.png"  width="600" height="400"/>
<br/><br/>

<p align="center"> [**Scout Navigation**](https://youtu.be/myETR4duN9g)

