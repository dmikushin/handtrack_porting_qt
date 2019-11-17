# handtrack_porting_qt
- description in main.cpp
  - 每次讀取shared memory時, 都要呼叫[find](https://github.com/team-seed/handtrack_porting_qt/blob/master/main.cpp#L41)取得記憶體位置
  - 不能事先把記憶體指標存下來，因為每次的memory的位置可能不同
  - [boost shared memory reference](https://www.boost.org/doc/libs/1_58_0/doc/html/interprocess/managed_memory_segments.html)
- based on [this mediapipe version](https://github.com/tratitude/mediapipe/tree/c05480afae186d4557982155a4be3f7e9138bb8e)
## usage
1. build handtracking if need
   - commad: source build_handtracking_gpu.sh
   - [build_handtracking_gpu.sh](https://github.com/tratitude/mediapipe/blob/master/build_handtracking_gpu.sh)
2. run handtracking
   - commad: source run_handtracking_gpu.sh
   - [run_handtracking_gpu.sh](https://github.com/tratitude/mediapipe/blob/master/run_handtracking_gpu.sh)
3. run qt application
