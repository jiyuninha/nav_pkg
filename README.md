  
# 🚀 SCOUT 2.0 Navigation 


<br/><br/>

## **Prerequisites**
---
- LiDAR localization [**Fast Localization**](https://github.com/hwan0806/FAST-LOCALIZATION)
  - pcd data(submap) [**data**](https://drive.google.com/file/d/1uJNYgAl9EpmnVGMoPCPvhDYSY3XAQz-t/view?usp=sharing)
  
- [**scout package**](https://github.com/agilexrobotics/scout_ros)
- [**ugv_sdk**](https://github.com/westonrobot/ugv_sdk)

<br/><br/>

## **Updates**
---


<br/><br/>

## **Development Enviorment Setup**
---
The code requires **`python>=3.8`**, as well as **`pytorch>=1.7`** and **`torchvision>=0.8`**. Please follow the instructions here to install both PyTorch and TorchVision dependencies. Installing both PyTorch and TorchVision with CUDA support is strongly recommended.

<br/>

### **Install with Docker**
- 본 Instructions들은 [**Youtube tutorial**](https://www.youtube.com/watch?v=JRD_xuqtHZU)과 같이 보며 따라하시면 편합니다.

<br/>

1. 터미널 하나를 여십시오:
```
git clone 
cd sparo_grounded_sam
```

2. grounded-sam 및 이에 대한 checkpoint들을 설치해줍니다.
```
make setup_base_grounded_sam
```

3. docker image build
```
bash ./run_docker.sh up ${input하고자 하는 image들의 경로}
```
4. docker container안으로 들어가서, 다음 명령어를 입력해줍니다.
```
cd /root/workspace
make setup_base_grounded_sam_in_docker
```

<br/><br/>


## **🤖 Create Detection Dataset**
---

<br/>

### **😺 Usage for Object Detection**
- 본 tutorial은 docker 환경이 setup되어있다는 전제 하에 실행이 가능합니다. 만약 docker 환경이 준비되어 있지 않으시다면, 다음 [**Step**](#-development-enviorment-setup) 을 확인하세요.
- 본 Instructions들은 [**Youtube tutorial**](https://www.youtube.com/watch?v=JRD_xuqtHZU)과 같이 보며 따라하시면 편합니다.

<br/>

1. config 폴더 안의 **'dino_object_detect_setting.py'** 라는 파일을 여십시오:
   - 본 파일에서 user가 setting 해야할 부분들을 기호에 맞게 수정하십시오. 이해가 잘 되지 않으시면 [**Youtube**](https://www.youtube.com/watch?v=JRD_xuqtHZU)를 참고하십시오.
  
2. 파일을 실행합니다.
```
make GD_object_detect_run_in_docker
```

3. 실행이 끝났다면 config에서 설정하였던 결과 저장 folder에 다음과 같이 결과들이 저장되어 있을 것입니다.
```
📦${save_root}
 ┗ 📂${log_comment}_0
   ┣ 📂boxes    # bounding box들의 좌표
   ┃ ┣ 📜image_1.txt
   ┃ ┣ 📜image_2.txt
   ┃ ┗ 📜image_3.txt
   ┣ 📂image    # object detection 했을 때의 이미지
   ┃ ┣ 📜image_1.png
   ┃ ┣ 📜image_2.png
   ┃ ┗ 📜image_3.png
   ┗ 📂logits   # object detect 했을 때 detction 신뢰도
     ┣ 📜image_1.txt
     ┣ 📜image_2.txt
     ┗ 📜image_3.txt
```

<br/><br/>

### **😺 Usage for Object Segmentation**
- 본 tutorial은 docker 환경이 setup되어있다는 전제 하에 실행이 가능합니다. 만약 docker 환경이 준비되어 있지 않으시다면, 다음 [**Step**](#-development-enviorment-setup) 을 확인하세요.
- 본 Instructions들은 [**Youtube tutorial**](https://www.youtube.com/watch?v=JRD_xuqtHZU)과 같이 보며 따라하시면 편합니다.

<br/>

1. config 폴더 안의 **'dino_object_segment_setting.py'** 라는 파일을 여십시오:
   - 본 파일에서 user가 setting 해야할 부분들을 기호에 맞게 수정하십시오. 이해가 잘 되지 않으시면 [**Youtube**](https://www.youtube.com/watch?v=JRD_xuqtHZU)를 참고하십시오.
  
2. 파일을 실행합니다.
```
make GD_segment_run_in_docker
```

3. 실행이 끝났다면 config에서 설정하였던 결과 저장 folder에 다음과 같이 결과들이 저장되어 있을 것입니다.
```
📦${save_root}
 ┗ 📂${log_comment}_0
   ┣ 📂boxes    # bounding box들의 좌표
   ┃ ┣ 📜image_1.txt
   ┃ ┣ 📜image_2.txt
   ┃ ┗ 📜image_3.txt
   ┣ 📂image    # object detection 했을 때의 이미지
   ┃ ┣ 📜image_1.png
   ┃ ┣ 📜image_2.png
   ┃ ┗ 📜image_3.png
   ┣ 📂logits   # object detect 했을 때 detction 신뢰도
   ┃ ┣ 📜image_1.txt
   ┃ ┣ 📜image_2.txt
   ┃ ┗ 📜image_3.txt
   ┗ 📂masks    # 각 detect된 object들의 mask 이미지
     ┣ 📂image_1
     ┣ 📂image_2
     ┣ 📂image_3
     ┣ 📜image_1.png
     ┣ 📜image_2.png
     ┗ 📜image_3.png
```
