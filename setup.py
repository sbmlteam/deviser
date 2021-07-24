from setuptools import setup
from setuptools import find_packages

setup(
    name='deviser',
    version='2.0',
    packages=find_packages(),
    include_package_data=True,
    entry_points={  # Optional
        'console_scripts': [
            'deviser=deviser.exit()'
            'deviser:main',
        ],
    },
    url='',
    license='',
    author='Sarah Keating',
    author_email='',
    description='', install_requires=['pytest']
)
