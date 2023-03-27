#define _CRT_SECURE_NO_WARNINGS
#include "Novel.h"
//unsigned int contentSize;
//char* title;
//char* content;
Novel::Novel(const char* title_, const char* content_)
{
	title = new char[strlen(title_) + 1];
	content = new char[strlen(content_) + 1];
	strcpy(title, title_);
	strcpy(content, content_);
	contentSize = (unsigned int)strlen(content_) + 1;
}
Novel::Novel(const Novel& novel)
{
	title = new char[strlen(novel.title) + 1];
	content = new char[strlen(novel.content) + 1];
	strcpy(title, novel.title);
	strcpy(content, novel.content);
	contentSize = (unsigned int)strlen(novel.content) + 1;
}
Novel& Novel::operator=(const Novel& novel)
{
	if (this != &novel)
	{
		if (title != nullptr || content != nullptr)
			delete title, delete content;
		title = new char[strlen(novel.title) + 1];
		content = new char[strlen(novel.content) + 1];
		strcpy(title, novel.title);
		strcpy(content, novel.content);
		contentSize = (unsigned int)strlen(novel.content) + 1;
	}
	return *this;
}
std::ostream& operator<<(std::ostream& os, const Novel& novel)
{
	os << novel.title << endl;
	os << novel.content << endl;
	return os;
}
Novel::~Novel()
{
	delete[] title;
	delete[] content;
	title = nullptr;
	content = nullptr;
}
//int novelNum;
//int maxNum;
//Novel* novelList;
NovelServer::NovelServer(const NovelServer& novelServer)
{
	novelNum = novelServer.novelNum;
	maxNum = novelServer.maxNum;
	novelList = new Novel[maxNum];
	for (int i = 0; i < maxNum; i++)
		novelList[i] = novelServer.novelList[i];
}
void NovelServer::addNovelInTheEnd(Novel& novel)
{
	if (novelNum == maxNum)
		printf("Storage Full. Add Novel Fail.\n");
	else
		novelList[novelNum++] = novel;
}
void NovelServer::removeNovelInTheEnd()
{
	if(novelNum)
		novelList[--novelNum].~Novel();
}
NovelServer& NovelServer::operator=(const NovelServer& novelServer)
{
	if (this != &novelServer)
	{
		if (novelList != nullptr)
			delete[] novelList;
		novelNum = novelServer.novelNum;
		maxNum = novelServer.maxNum;
		novelList = new Novel[maxNum];
		for (int i = 0; i < maxNum; i++)
			novelList[i] = novelServer.novelList[i];
	}
}
std::ostream& operator<<(std::ostream& os, const NovelServer& novelServer)
{
	for (int i = 0; i < novelServer.novelNum; i++)
		os << novelServer.novelList[i] << endl;
}
NovelServer::~NovelServer()
{
	delete[] novelList;
	novelList = nullptr;
}