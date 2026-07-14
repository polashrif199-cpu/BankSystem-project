#pragma once

#include <iostream>

#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"

using namespace std;

class Screens
{
public:

	// شاشة اسم البنك
	static void bankName();

	// رسالة الترحيب
	static void welcome();

	// قائمة تسجيل الدخول
	static void loginOptions();

	// استقبال اختيار المستخدم
	static int loginAs();

	// رسالة الاختيار الخاطئ
	static void invalid(int choice);

	// رسالة تسجيل الخروج
	static void logout();

	// شاشة تسجيل الدخول
	static void loginScreen(int choice);

	// تشغيل البرنامج بالكامل
	static void runApp();
};