from setuptools import setup
from setuptools import find_packages

setup(
    name='deviser',
    version='2.0',
    packages=find_packages(),
    entry_points={  # Optional
        'console_scripts': [
            'deviser=deviser:main',
        ],
    },
    url='',
    license='',
    author='Sarah Keating',
    author_email='',
    description=''
)
