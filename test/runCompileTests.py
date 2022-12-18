
libraryName = "EncoderTool"

boards = [
    ""
    "teensy31",
    "teensy41",
    "uno"
]

examples = [
    "examples/1_basic/simpleEncoder",
    "examples/1_basic/polledEncoder",
    "examples/1_basic/encoderButton",
    "examples/2_multiplexing/multiplexed_4051",
    "examples/2_multiplexing/multiplexed_4067",
    "examples/2_multiplexing/multiplexed_74165",
    "examples/2_multiplexing/multiplexed_matrix",
    "examples/2_multiplexing/multiplexed_MCP23S17",
    "examples/3_callbacks/mplexCallbacks",
    "examples/3_callbacks/singleEncCallback",
    "examples/8_applications/SignalAnalysis",
]

dependencies=[
    "SPI",
    "wire",
    "adafruit/Adafruit BusIO",
    "adafruit/Adafruit MCP23017 Arduino Library"
]

#*************************************************************************************************
import subprocess
import tempfile
import os
import distutils.dir_util


print("\n================================ SETTING UP TEST PROJECT ================================")

targetPrjFolder = os.path.join(tempfile.gettempdir(), libraryName)
targetLibFolder = os.path.join(targetPrjFolder,"lib",libraryName)
targetSrcFolder = os.path.join(targetPrjFolder,"src")

if os.path.isdir(targetPrjFolder): # start with a fresh setup
    distutils.dir_util.remove_tree(targetPrjFolder)

distutils.dir_util.mkpath(targetPrjFolder)

initParams = ["pio","project", "init", "-s"]
initParams.append("--project-dir=" + targetPrjFolder)
for board in boards:
    initParams.append("--board=" + board)

opt = "--project-option=lib_deps="
for dep in dependencies:
    opt += (dep + '\n')

initParams.append(opt)

result = subprocess.run(initParams)


distutils.dir_util.copy_tree(".",targetLibFolder)

totalExamples = str(len(examples)*len(boards))
currentExample = 1

print("\n================================== COMPILING EXAMPLES ===================================")

for board in boards:
    print('{:57}'.format("SKETCH") + '{:25}'.format("BOARD")+ " STATUS" )
    for example in examples:
        counter =  (f"{currentExample}/{totalExamples}").center(8)
        currentExample += 1
        print("- " + '{:55}'.format(example) + '{:25}'.format(board) + counter, end="\r", flush=True)

        if os.path.isdir(targetSrcFolder):
            distutils.dir_util.remove_tree(targetSrcFolder)
        distutils.dir_util.copy_tree (example,targetSrcFolder)

        result = subprocess.run(["pio", "run",  "-e"+board,  "--project-dir=" + targetPrjFolder],capture_output=True)
        #result = subprocess.run(["pio", "run",  "-e"+board,  "--project-dir=" + targetPrjFolder])
        #print("\033[K",end='')

        print("- " + '{:55}'.format(example) + '{:25}'.format(board), end='', flush=True)
        if result.returncode == 0:
            print("\033[92m[PASSED]\033[0m"+"       ")
        else:
            print("\033[91m[FAILED]\033[0m"+"       ")
    print(' ')
