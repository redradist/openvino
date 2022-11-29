# Install OpenVINO™ Runtime on Windows from an Archive File {#openvino_docs_install_guides_installing_openvino_from_archive_windows}

With the OpenVINO™ 2022.2 release, you can download and use archive files to install OpenVINO Runtime. The archive files contain pre-built binaries and library files needed for OpenVINO Runtime, as well as code samples. 

Installing OpenVINO Runtime from archive files is recommended for C++ developers. If you are working with Python, the PyPI package has everything needed for Python development and deployment on CPU and GPUs. See the [Install OpenVINO from PyPI](installing-openvino-pip.md) page for instructions on how to install OpenVINO Runtime for Python using PyPI.

> **NOTE**: Since the OpenVINO™ 2022.1 release, the following development tools: Model Optimizer, Post-Training Optimization Tool, Model Downloader and other Open Model Zoo tools, Accuracy Checker, and Annotation Converter can be installed via [pypi.org](https://pypi.org/project/openvino-dev/) only.

See the [Release Notes](https://software.intel.com/en-us/articles/OpenVINO-RelNotes) for more information on updates in the latest release.

## System Requirements

@sphinxdirective
.. tab:: Operating Systems

  * Microsoft Windows 10, x86, 64-bit
  * Microsoft Windows 11, x86, 64-bit

.. tab:: Hardware

  Optimized for these processors:

  * 6th to 12th generation Intel® Core™ processors and Intel® Xeon® processors 
  * 3rd generation Intel® Xeon® Scalable processor (formerly code named Cooper Lake)
  * Intel® Xeon® Scalable processor (formerly Skylake and Cascade Lake)
  * Intel Atom® processor with support for Intel® Streaming SIMD Extensions 4.1 (Intel® SSE4.1)
  * Intel Pentium® processor N4200/5, N3350/5, or N3450/5 with Intel® HD Graphics
  * Intel® Iris® Xe MAX Graphics
  * Intel® Neural Compute Stick 2
  * Intel® Vision Accelerator Design with Intel® Movidius™ VPUs
  
.. tab:: Processor Notes

  Processor graphics are not included in all processors. 
  See `Product Specifications`_ for information about your processor.
  
  .. _Product Specifications: https://ark.intel.com/

.. tab:: Software

  * `Microsoft Visual Studio 2019 with MSBuild <https://visualstudio.microsoft.com/vs/older-downloads/>`_ or `Microsoft Visual Studio 2022 <http://visualstudio.microsoft.com/downloads/>`_
  * `CMake 3.14 or higher, 64-bit <https://cmake.org/download/>`_ (optional, only required for building sample applications)
  * `Python 3.7 - 3.10, 64-bit <https://www.python.org/downloads/windows/>`_

  .. note::
     To install Microsoft Visual Studio 2019, follow the `Microsoft Visual Studio installation guide <https://docs.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=vs-2019>`_. You can choose to download the Community version. During installation in the **Workloads** tab, choose **Desktop development with C++**.

  .. note::
    You can either use `cmake<version>.msi` which is the installation wizard or `cmake<version>.zip` where you have to go into the `bin` folder and then manually add the path to environmental variables.
  
  .. important::
    When installing Python, make sure you click the option **Add Python 3.x to PATH** to `add Python <https://docs.python.org/3/using/windows.html#installation-steps>`_ to your `PATH` environment variable.

@endsphinxdirective

## Installing OpenVINO Runtime

### <a name="install-openvino"></a>Step 1: Download and Install OpenVINO Core Components

1. Create an `Intel` folder in the `C:\Program Files (x86)\` directory. Skip this step if the folder already exists.
   
   You can also do this via command-lines. Open a new command prompt window as administrator by right-clicking **Command Prompt** from the Start menu and select **Run as administrator**, and then run the following command:
   ```sh
   mkdir "C:\Program Files (x86)\Intel"
   ```
   > **NOTE**: `C:\Program Files (x86)\Intel` is the recommended folder. You may also use a different path if desired or if you don't have administrator privileges on your computer.

2. Download the [OpenVINO Runtime archive file for Windows](https://storage.openvinotoolkit.org/repositories/openvino/packages/2022.2/windows/) to your local `Downloads` folder.
   
   If you prefer using command-lines, run the following commands in the command prompt window you opened:
   ```sh
   cd <user_home>/Downloads
   curl -L https://storage.openvinotoolkit.org/repositories/openvino/packages/2022.2/windows/w_openvino_toolkit_windows_2022.2.0.7713.af16ea1d79a_x86_64.zip --output openvino_2022.2.0.7713.zip
   ```
   > **NOTE**: A `.sha256` file is provided together with the archive file to validate your download process. To do that, download the `.sha256` file from the same repository and run `CertUtil -hashfile openvino_2022.2.0.7713.zip SHA256`. Compare the returned value in the output with what's in the `.sha256` file: if the values are the same, you have downloaded the correct file successfully; if not, create a Support ticket [here](https://www.intel.com/content/www/us/en/support/contact-intel.html).


3. Use your favorite tool to extract the archive file, rename the extracted folder as `openvino_2022.2.0.7713`, and move it to the `C:\Program Files (x86)\Intel` directory.
   
   To do this step using command-lines, run the following commands in the command prompt window you opened:
   ```sh
   tar -xf openvino_2022.2.0.7713.zip
   ren w_openvino_toolkit_windows_2022.2.0.7713.af16ea1d79a_x86_64 openvino_2022.2.0.7713
   move openvino_2022.2.0.7713 "C:\Program Files (x86)\Intel"
   ```

4. For simplicity, it is useful to create a symbolic link. Open a command prompt window as administrator (see Step 1 for how to do this) and run the following commands:
   ```sh
   cd C:\Program Files (x86)\Intel
   mklink /D openvino_2022 openvino_2022.2.0.7713
   ```
   > **NOTE**: If you have already installed a previous release of OpenVINO 2022, a symbolic link to the `openvino_2022` folder may already exist. If you want to override it, nagivate to the `C:\Program Files (x86)\Intel` folder and delete the existing linked folder before running the `mklink` command.


Congratulations, you finished the installation! The `C:\Program Files (x86)\Intel\openvino_2022` folder now contains the core components for OpenVINO. If you used a different path in Step 1, you will find the `openvino_2022` folder there. The path to the `openvino_2022` directory is also referred as `<INSTALL_DIR>` throughout the OpenVINO documentation.

### <a name="set-the-environment-variables"></a>Step 2: Configure the Environment

You must update several environment variables before you can compile and run OpenVINO™ applications. Open the Command Prompt, and run the `setupvars.bat` batch file to temporarily set your environment variables. If your <INSTALL_DIR> is not `C:\Program Files (x86)\Intel\openvino_2022`, use the correct directory instead.

```sh
"C:\Program Files (x86)\Intel\openvino_2022\setupvars.bat"
```

> **Important**: The above command must be re-run every time a new Command Prompt window is opened.

> **NOTE**: If you see an error indicating Python is not installed, Python may not be added to the PATH environment variable (as described [here](https://docs.python.org/3/using/windows.html#finding-the-python-executable)). Check your system environment variables, and add Python if necessary.

The environment variables are set. Continue to the next section if you want to download any additional components.

### <a name="model-optimizer">Step 3 (Optional): Install Additional Components</a>

OpenVINO Development Tools is a set of utilities for working with OpenVINO and OpenVINO models. It provides tools like Model Optimizer, Benchmark Tool, Post-Training Optimization Tool, and Open Model Zoo Downloader. If you install OpenVINO Runtime using archive files, OpenVINO Development Tools must be installed separately.

See the [Install OpenVINO Development Tools](installing-model-dev-tools.md) page for step-by-step installation instructions.

OpenCV is necessary to run demos from Open Model Zoo (OMZ). Some OpenVINO samples can also extend their capabilities when compiled with OpenCV as a dependency. To install OpenCV for OpenVINO, see the [instructions on GitHub](https://github.com/opencv/opencv/wiki/BuildOpenCV4OpenVINO).

### <a name="optional-steps"></a>Step 4 (Optional): Configure Inference on non-CPU Devices
OpenVINO Runtime has a plugin architecture that enables you to run inference on multiple devices without rewriting your code. Supported devices include integrated GPUs, discrete GPUs, NCS2, VPUs, and GNAs. See the instructions below to set up OpenVINO on these devices.

@sphinxdirective
.. tab:: GPU

   To enable the toolkit components to use processor graphics (GPU) on your system, follow the steps in :ref:`GPU Setup Guide <gpu guide windows>`.

.. tab:: VPU

   To install and configure your Intel® Vision Accelerator Design with Intel® Movidius™ VPUs, see the :ref:`VPU Configuration Guide <vpu guide windows>`.
   
.. tab:: NCS 2
   
   No additional configurations are needed.
   
.. tab:: GNA

   To enable the toolkit components to use Intel® Gaussian & Neural Accelerator (GNA) on your system, follow the steps in :ref:`GNA Setup Guide <gna guide windows>`.
   
@endsphinxdirective

## <a name="get-started"></a>What's Next?
Now that you've installed OpenVINO Runtime, you're ready to run your own machine learning applications! Learn more about how to integrate a model in OpenVINO applications by trying out the following tutorials.

@sphinxdirective
.. tab:: Get started with Python

   Try the `Python Quick Start Example <https://docs.openvino.ai/2022.2/notebooks/201-vision-monodepth-with-output.html>`_ to estimate depth in a scene using an OpenVINO monodepth model in a Jupyter Notebook inside your web browser.
   
   .. image:: https://user-images.githubusercontent.com/15709723/127752390-f6aa371f-31b5-4846-84b9-18dd4f662406.gif
      :width: 400

   Visit the :ref:`Tutorials <notebook tutorials>` page for more Jupyter Notebooks to get you started with OpenVINO, such as:
   
   * `OpenVINO Python API Tutorial <https://docs.openvino.ai/2022.2/notebooks/002-openvino-api-with-output.html>`_
   * `Basic image classification program with Hello Image Classification <https://docs.openvino.ai/2022.2/notebooks/001-hello-world-with-output.html>`_
   * `Convert a PyTorch model and use it for image background removal <https://docs.openvino.ai/2022.2/notebooks/205-vision-background-removal-with-output.html>`_

.. tab:: Get started with C++

   Try the `C++ Quick Start Example <openvino_docs_get_started_get_started_demos.html>`_ for step-by-step instructions on building and running a basic image classification C++ application.
   
   .. image:: https://user-images.githubusercontent.com/36741649/127170593-86976dc3-e5e4-40be-b0a6-206379cd7df5.jpg
      :width: 400

   Visit the :ref:`Samples <code samples>` page for other C++ example applications to get you started with OpenVINO, such as:
   
   * `Basic object detection with the Hello Reshape SSD C++ sample <openvino_inference_engine_samples_hello_reshape_ssd_README.html>`_
   * `Automatic speech recognition C++ sample <openvino_inference_engine_samples_speech_sample_README.html>`_

@endsphinxdirective

## <a name="uninstall"></a>Uninstalling OpenVINO Runtime

To uninstall OpenVINO, follow the steps on the [Uninstalling page](uninstalling-openvino.md).

## Additional Resources

## Additional Resources

* :ref:`Troubleshooting Guide for OpenVINO Installation & Configuration <troubleshooting guide for install>`
* Converting models for use with OpenVINO™: :ref:`Model Optimizer Developer Guide <deep learning model optimizer>`
* Writing your own OpenVINO™ applications: :ref:`OpenVINO™ Runtime User Guide <deep learning openvino runtime>`
* Sample applications: :ref:`OpenVINO™ Toolkit Samples Overview <code samples>`
* Pre-trained deep learning models: :ref:`Overview of OpenVINO™ Toolkit Pre-Trained Models <model zoo>`
* IoT libraries and code samples in the GitHUB repository: `Intel® IoT Developer Kit`_ 
      
<!---  
   To learn more about converting models from specific frameworks, go to: 
   * :ref:`Convert Your Caffe Model <convert model caffe>`
   * :ref:`Convert Your TensorFlow Model <convert model tf>`
   * :ref:`Convert Your Apache MXNet Model <convert model mxnet>`
   * :ref:`Convert Your Kaldi Model <convert model kaldi>`
   * :ref:`Convert Your ONNX Model <convert model onnx>`
--->    
.. _Intel® IoT Developer Kit: https://github.com/intel-iot-devkit

@endsphinxdirective