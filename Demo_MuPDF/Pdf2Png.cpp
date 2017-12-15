// Pdf2Png.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<string>
#include "MuPDFConvert.h"
#include<vector>
//#include <Windows.h>
#include <afx.h>
#include<cstdio>
using namespace std;


wchar_t* StringToWchar(const string& s)  
{  
	char* m_char;  
    wchar_t* m_wchar;
    const char* c=s.c_str();  
    int len = MultiByteToWideChar(CP_ACP,0,c,strlen(c),NULL,0);  
    m_wchar=new wchar_t[len+1];  
    MultiByteToWideChar(CP_ACP,0,c,strlen(c),m_wchar,len);  
    m_wchar[len]='\0';  
    return m_wchar;  
} 

bool GetAllFilesList(string file_path,
					vector<string> &files_list, 
					vector<string> &folders_list)
{
	bool bRtn = false;
	if(file_path.empty())
	{
		return bRtn;
	}

	WIN32_FIND_DATA find_data;
	HANDLE hFind = FindFirstFileA(file_path.c_str(), &find_data);
	if(hFind == INVALID_HANDLE_VALUE)
	{
		return bRtn;
	}
	string find_path = file_path + "\\*.*";
	hFind = FindFirstFile(find_path.c_str(), &find_data);
	do
	{
		if((string)find_data.cFileName == "." || (string)find_data.cFileName == "..")
		{
			continue;
		}

		string full_path = file_path + "\\" + find_data.cFileName;
		if(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			vector<string> file_list_tmp;
			vector<string> folder_list_tmp;
			folders_list.push_back(full_path);
			GetAllFilesList(full_path, file_list_tmp, folder_list_tmp);
			if(!file_list_tmp.empty())
			{
				files_list.insert(files_list.end(), file_list_tmp.begin(), file_list_tmp.end());
			}
			if(!folder_list_tmp.empty())
			{
				folders_list.insert(folders_list.end(), folder_list_tmp.begin(), folder_list_tmp.end());
			}
		}
		else
		{
			files_list.push_back(full_path);
		}
	} while(FindNextFile(hFind, &find_data));

	FindClose(hFind);

	return bRtn;
}

int old_tmain(int argc, _TCHAR* argv[])
{
	//获取文件名
	std::string path="C:\Users\Lenovo\Desktop\tmp\1.png";
	std::string suffixStr = path.substr(path.find_last_of('.') + 1);
	std::string prefixStr = path.substr(0,path.find_last_of('.')-1);
	std::cout<<suffixStr<<std::endl;
	std::cout<<prefixStr<<std::endl;
	

	

	//接口测试 将PDF转换为图片格式
	CMuPDFConvert pdfConvert;
	int nNum = 0;
	pdfConvert.Pdf2Png(L"test.pdf", "test", nNum);
	

	//转换文件夹中的pdf文件
	char file_path[100]= "C:\\Users\\Lenovo\\Desktop\\tmp\\testPdfFile";
	vector<string> files, folders;
	GetAllFilesList(file_path, files, folders);
	cout << files.size() << endl;
	int countPdf= 0;
	for (int i = 0; i < files.size(); i++) {
		string filename = files[i];
		cout<<filename<<endl;
		std::string suffixFname = filename.substr(filename.find_last_of('.') + 1);
		if(suffixFname=="pdf"||suffixFname=="PDF"){
			countPdf++;//统计pdf数量
			std::string prefixFname = filename.substr(0,filename.find_last_of('.'));//文件前缀
			
			//将文件名称转换为接口所用的类型
			std::wstring wName = std::wstring(filename.begin(), filename.end());
			const wchar_t *NameChar = wName.c_str();
			
			//文件前缀转为接口所用类型
			const char* preNameChar= prefixFname.c_str();
			pdfConvert.Pdf2Png(NameChar, preNameChar, nNum);
		}
	} 
	cout<<"convert succeed"<<endl;
	cout<<"the folders have "<<countPdf<<" pdfs"<<endl;
	getchar();
	return 0;
}
int main(){
	 //创建与删除文件夹测试
	 //string dirName = "./tmpdirtest";    
	 //if(CreateDirectory(dirName.c_str(), NULL)){
		//cout<<"create succeed"<<endl;
	 //}
	 //if(RemoveDirectory(dirName.c_str())){
		//cout<<"remove succeed"<<endl;	 
	 //}

	
	char* s="C:\\Users\\Lenovo\\Desktop\\2017秋课程表.pdf";
	string filename=s;
	std::string suffixFname = filename.substr(filename.find_last_of('.') + 1);
	if(suffixFname=="pdf"||suffixFname=="PDF"){

		std::string prefixFname = filename.substr(0,filename.find_last_of('.'));//文件前缀
		string 	flodersName= prefixFname.substr(0,prefixFname.find_last_of('\\'));
		//将文件名称转换为接口所用的类型
		//std::wstring wName = std::wstring(filename.begin(), filename.end());
		//const wchar_t *NameChar = wName.c_str();
		//wchar_t * NameChar = new wchar_t[filename.size()];  
		//swprintf(NameChar,100,L"%S",filename.c_str()); 
			

		wchar_t* NameChar=StringToWchar(filename);


		//文件前缀转为接口所用类型
		const char* preNameChar= prefixFname.c_str();
		CMuPDFConvert pdfConvert;
		int nNum = 0;
		pdfConvert.Pdf2Png(NameChar, preNameChar, nNum);
		vector<string> files, folders;
		string file_path= flodersName;
		GetAllFilesList(file_path, files, folders);
		for (int i = 0; i < files.size(); i++) {
			string filename1 = files[i];
			std::string suffixFname1 = filename1.substr(filename1.find_last_of('.') + 1);
			std::string prefixFname1 = filename1.substr(0,filename1.find_last_of('.'));
			if(suffixFname1=="png"&& (prefixFname1.find(prefixFname)!= prefixFname1.npos)){
				cout << filename1 << endl;
				//接口程序
				const char *p=filename1.c_str();
				//remove(p);//删除所生成的png文件
			}

		}
		
	}

	getchar();
	return 0;
}

