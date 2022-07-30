#pragma once

#include "pch.h"
#include "Form1.h"

using namespace System;
using namespace System::Threading;
using namespace System::Windows::Forms;

void threadStart()
{
    Application::Run(gcnew Form());
}
[System::STAThread] // This will not work!
int main(array<System::String^>^ args)
{
    Thread^ t = gcnew Thread(gcnew ThreadStart(threadStart));
    t->ApartmentState = ApartmentState::STA;
    t->Start();
    return 0;
}