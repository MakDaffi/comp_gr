#pragma once

namespace Okunkov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	mat3 T = mat3(1.f); // �������, � ������� ������������� ��� ��������������
    // ������������� - ��������� �������
	mat3 initT; // ������� ���������� ��������������

	float lines[] = {
		// ������
		0.5f,3.f,1.f,4.5f, // �� ����� ���� ����� �� ���
		1.f,4.5f,0.5f,6.f, // ����� ��� ����� ����� �����
		0.5f,6.f,0.5f, 7.5f, // ����� ��� �����
		0.5f, 7.5f,1.f,8.f, // ����� ��� ���� �����
		1.f,8.f,1.5f,8.f, // ����� ��� ���� ��������
		1.5f,8.f,2.f,7.5f, // ����� ��� ���� ������
		2.f,7.5f,1.5f, 6.f, // ����� ��� ������ ������ ����
		1.5f, 6.f,1.5f,4.5f, // ����� ��� ������ �� �������
		1.5f,4.5f,3.f,4.5f, // �������
		3.f,4.5f,3.f,6.f, // ������ ��� ����� ����� �����
		3.f,6.f,2.5f,7.5f, // ������ ��� �����
		2.5f,7.5f,3.f,8.f, // ������ ��� ���� �����
		3.f,8.f,3.5f,8.f, // ������ ��� ���� ��������
		3.5f,8.f,4.f,7.5f, // ������ ��� ���� ������
		4.f,7.5f,4.f,6.f, // ������ ��� ������ ����
		4.f,6.f,3.5f,4.5f, // ������ ��� ������
		3.5f,4.5f,4.f,3.f, // �� ������� ��� ���� �� ����
		4.f,3.f,3.5f,1.5f, // ������ �����
		3.5f,1.5f,2.5f,1.f, // ���������� ������
		2.5f,1.f,2.f,1.f, // ���������� �����
		2.f,1.f,1.f,1.5f, // ���������� �����
		1.f,1.5f,0.5f,3.f, // ����� �����
		// ��������
		4.f,3.f,5.5f,3.5f, // ����� �� ������ ������
		5.5f,3.5f,7.f,3.5f, // ����� ����
		7.f,3.5f,7.5f,2.5f, // ����� ������ �� ������
		7.5f,2.5f,8.f,2.5f, // ����� ������
		8.f,2.5f,8.f,2.f, // ����� ������
		8.f,2.f,7.5f,2.f, // ����� ��� ������ ������
		7.5f,2.f,7.5f,0.5f, // ������ ���� ������ ������ ����
		7.5f,0.5f,6.5f,0.5f, // ������ ���� ���
		6.5f,0.5f,6.5f,1.f, // ������ ���� �����
		6.5f,1.f,6.f,1.f, // ����� ������ ���
		6.f,1.f,6.f,0.5f, // ����� ������ ���� ������
		6.f,0.5f,5.f,0.5f, // ����� ������ ���� ���
		5.f,0.5f,5.f,1.f, // ����� ������ ���� �����
		5.f,1.f,4.f,1.f, // ����� ������� � ��������� ������
		4.f,1.f,4.f,0.5f, // ������ �������� ���� ������
		4.f,0.5f,3.f,0.5f, // ������ �������� ���� ���
		3.f,0.5f,3.f,1.f, // ������ �������� ���� �����
		3.f,1.f,2.5f,1.f, // ����� �������� ���
		2.5f,1.f,2.5f,0.5f, // �������� ���� ������
		2.5f,0.5f,1.5f,0.5f, // �������� ���� ���
		1.5f,0.5f,1.5f,1.25f, // �������� ���� �����
		// ����� ����
		1.5f,3.5f,1.5f,3.f, // ����� ���� ����� ������ ����
		1.5f,3.f,2.f,3.f, // ����� ���� ���
		2.f, 3.f,2.f,3.5f, // ����� ���� ������
		2.f,3.5f,1.5f,3.5f, // ����� ���� ����
		// ������ ����
		2.5f,3.5f,2.5f,3.f, // ������ ���� �����
		2.5f,3.f,3.f, 3.f, // ������ ���� �����
		3.f,3.f,3.f,3.5f, // ������ ���� ������
		3.f,3.5f,2.5f,3.5f, // ������ ���� ������
		// ����� ��������
		1.f,5.5f,1.f,7.f, // ����� ����� ��������
		3.5f,5.5f,3.5f,7.f, // ������ ����� ��������
		// ���
		2.f,2.5f,2.5f,2.5f, // ��� ������
		2.5f,2.5f,2.25f,2.f, // ��� ������
		2.25f,2.f,2.f,2.5f // ��� �����
	};

	float lines1[] = {
		// ����
		3.f,12.f,3.f,12.5f,  // ����� ����
		3.f,12.5f,4.5f,13.f, // �� ���� � �����
		4.5,13.f,6.5f,13.f,  // ����� ��� �������
		6.5f,13.f,8.f,12.5f, // �� ����� � ����
		8.f,12.5f,8.f,12.f,  // ������ ����
		8.f,12.f,5.5f,10.5f, // ������ ����� ����������
		5.5f,10.5f,3.f,12.f, // ����� ����� ����������
		// ���
		3.5f,12.f,4.f,12.5f,
		4.f,12.5f,5.f,11.5f,
		5.f,11.5f,6.f,11.5f,
		6.f,11.5f,7.f,12.5,
		7.f,12.5,7.5f,12.f,
		// ������ �����
		4.5,13.f,4.5f,14.f,
		4.5f,14.f,5.f,14.5f,
		5.f,14.5f,5.5f,14.f,
		5.5f,14.f,5.5,13.f,
		// ����� ����
		5.5f,14.f,6.f,14.5f,
		6.f,14.5f,6.5f,14.f,
		6.5f,14.f,6.5f,13.f,
		// ������ ��������
		4.75f,13.f,4.75f,13.5f,
		4.75f,13.5f,5.f,14.f,
		5.f,14.f,5.25f,13.5f,
		5.25f,13.5f,5.25,13.f,
		// ����� ��������
		5.75f,13.f,5.75f,13.5f,
		5.75f,13.5f,6.f,14.f,
		6.f,14.f,6.25f,13.5f,
		6.25f,13.5f,6.25f,13.f,
		// ������ ����
		4.875f,13.f,4.875f,13.25f,
		4.875f,13.25f,5.f,13.5f,
		5.f,13.5f,5.125f,13.25f,
		5.125f,13.25f,5.125,13.f,
		// ����� ����
		5.875f,13.f,5.875f,13.25f,
		5.875f,13.25f,6.f,13.5f,
		6.f,13.5f,6.125f,13.25f,
		6.125f,13.25f,6.125f,13.f,
		// ���
		4.5f,11.125f,4.5f,10.5f,
		6.5f,11.125f,6.5f,10.5f,
		// �������
		4.f,11.f,4.f,9.f,
		4.f,9.f,5.5f,10.5f,
		4.f,11.f,5.5f,9.5f,
		5.5f,9.5f,7.f,11.f,
		7.f,11.f,7.f,9.f,
		7.f,9.f,5.5f,10.5f,
		// ������ �����
		5.5f,9.5f,6.f,7.5f,
		6.f,7.5f,7.f,6.f,
		7.f,6.f,7.f,7.f,
		7.f,7.f,8.f,6.5f,
		8.f,6.5f,7.5f,7.5f,
		7.5f,7.5f,8.5f,8.f,
		8.5f,8.f,7.f,8.f,
		7.f,8.f,6.75f,9.25f,
		// ����� �����
		5.5f,9.5f,5.f,7.5f,
		5.f,7.5f,4.f,6.f,
		4.f,6.f,4.f,7.f,
		4.f,7.f,3.f,6.5f,
		3.f,6.5f,3.5f,7.5f,
		3.5f,7.5f,2.5f,8.f,
		2.5f,8.f,4.f,8.f,
		4.f,8.f,4.25f,9.25f,
		// ������ �����
		1.f,5.5f,10.f,5.5f,
		1.f,5.5f,1.5f,8.5f,
		1.5f,8.5f,2.f,10.f,
		10.f,5.5f,9.5f,8.5f,
		9.5f,8.5f,9.f,10.f,
		// ����� ������ �����
		4.f,10.5f,2.5f,11.5f,
		2.5f,11.5f,1.5f,11.f,
		1.5f,11.f,2.f,10.f,
		2.f,10.f,3.5f,8.f,
		2.5f,10.5f,4.f,8.f,
		3.f,8.5f,2.f,8.5f,
		3.f,8.5f,3.1f,8.6f,
		2.f,8.5f,1.5f,8.f,
		1.5f,8.f,1.5f,7.5f,
		1.5f,7.5f,2.f,8.f,
		1.5f,7.5f,2.f,7.f,
		2.f,7.f,2.5f,7.5f,
		2.5f,7.5f,3.5f,7.5f,
		// ������ ������ �����
		7.f,10.5f,8.5f,11.5f,
		8.5f,11.5f,9.5f,11.f,
		9.5f,11.f,9.f,10.f,
		9.f,10.f,7.5f,8.f,
		7.f,8.f,8.5f,10.5f,
		7.5f,8.f,8.5,8.5f,
		8.5,8.5f,9.f,8.5f,
		9.f,8.5f,9.5f,8.f,
		9.5f,8.f,9.5f,7.5f,
		9.5f,7.5f,9.f,8.f,
		9.5f,7.5f,9.f,7.f,
		9.f,7.f,8.5f,7.5f,
		8.5f,7.5f,7.5f,7.5f,
		// ����� �����
		4.5f,5.5f,4.f,2.f,
		4.f,2.f,4.5f,3.f,
		4.5f,3.f,4.5f,0.5f,
		4.5f,0.5f,5.f,1.5f,
		5.f,1.5f,5.5f,0.f,
		5.5f,0.f,6.f,1.5f,
		6.f,1.5f,6.5f,0.5f,
		6.5f,0.5f,6.5f,3.f,
		6.5f,3.f,7.f,2.f,
		7.f,2.f,6.5f,5.5f,
		//�����
		4.f,2.f,3.5f,3.5f,
		3.5f,3.5f,3.5f,2.f,
		3.5f,2.f,3.f,4.5f,
		3.f,4.5f,3.f,2.5f,
		3.f,2.5f,2.f,4.f,
		2.f,4.f,2.f,2.5f,
		2.f,2.5f,1.f,3.f,
		1.f,3.f,2.f,0.f,
		2.f,0.f,9.f,0.f,
		9.f,0.f,10.f,3.f,
		10.f,3.f,9.f,2.5f,
		9.f,2.5f,9.f,4.f,
		9.f,4.f,8.f,2.5f,
		8.f,2.5f,8.f,4.5f,
		8.f,4.5f,7.5f,2.f,
		7.5f,2.f,7.5f,3.5f,
		7.5f,3.5f,7.f,2.f,
		// ����� �� ������ �����
		2.f,5.5f,1.5f,6.f,
		1.5f,6.f,2.f,6.5f,
		2.f,6.5f,2.5f,6.5f,
		2.5f,6.5f,3.f,6.f,
		3.f,6.f,2.5f,5.5f,
		6.f,7.5f,5.5f,7.f,
		5.5f,7.f,6.f,6.5f,
		6.f,6.5f,6.5f,6.5f,
		6.5f,6.5f,6.6f,6.6f,
		9.5f,6.5f,9.f,6.f,
		9.f,6.f,8.5f,6.f,
		8.5f,6.f,8.f,6.5f,
		8.f,6.5f,8.5f,7.f,
		8.5f,7.f,9.f,7.f,
		9.f,7.f,9.5f,6.5f,
		2.f,9.f,2.5f,8.5f,
		2.f,9.f,2.5f,9.35f,
		9.f,9.5f,8.5f,9.f,
		8.5f,9.f,8.25f,9.f,
		9.f,9.5f,8.82f,9.78f
	};


	float Vx = 8.5f; // ������ ������� �� �����������
	float Vy = 8.5f; // ������ ������� �� ���������
	float aspectFig = Vx / Vy; // ����������� ������ �������
	float Vx1 = 10.5f; // ������ ������� �� �����������
	float Vy1 = 15.5f; // ������ ������� �� ���������
	float aspectFig1 = Vx1 / Vy1; // ����������� ������ �������

	unsigned int arrayLength = sizeof(lines) / sizeof(float);
	unsigned int arrayLength1 = sizeof(lines1) / sizeof(float);

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool keepAspectRatio, a; // �������� - ��������� �� ����������� ������ �������?
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		if (a) {
			Graphics^ g = e->Graphics;
			g->Clear(Color::Aquamarine);

			Pen^ blackPen = gcnew Pen(Color::Black, 2);

			float Wx = ClientRectangle.Width; //������ ���� �� �����������
			float Wy = ClientRectangle.Height; //������ ���� �� ���������

			float aspectForm = Wx / Wy; //����������� ������ ���� ���������
			float Sx, Sy;
			if (keepAspectRatio) {
				// ������������ ���������� ��� ���������� ��������� ����������� ������
				Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
			}
			else {
				Sx = Wx / Vx; // ����������� ���������� �� ��� Ox
				Sy = Wy / Vy; // ����������� ���������� �� ��� Oy
			}

			float Ty = Sy * Vy; // �������� � ������������� ������� �� ��� Oy ����� ����� �����
			initT = translate(0.f, Ty) * scale(Sx, -Sy); // �������������� ����������� ������ ������
            // ������� ���������������, � ����� �������
            // � initT ��������� ��� ��� ��������������
			mat3 M = T * initT; // ���������� ���������� �������������� �
			// ����������� ��������������
			for (int i = 0; i < arrayLength; i += 4) {
				vec3 A = vec3(lines[i], lines[i + 1], 1.f); // ������ ������� � ���������� �����������
				vec3 B = vec3(lines[i + 2], lines[i + 3], 1.f); // ����� ������� � ���������� �����������
				vec2 a = normalize(M * A); // ������ ������� ����� ��������������
				vec2 b = normalize(M * B); // ����� ������� ����� ��������������
				g->DrawLine(blackPen, a.x, a.y, b.x, b.y); // ��������� �������
			}
		}
		else {
			Graphics^ g = e->Graphics;
			g->Clear(Color::Red);

			Pen^ blackPen = gcnew Pen(Color::Black, 2);

			float Wx = ClientRectangle.Width; //������ ���� �� �����������
			float Wy = ClientRectangle.Height; //������ ���� �� ���������

			float aspectForm = Wx / Wy; //����������� ������ ���� ���������
			float Sx, Sy;
			if (keepAspectRatio) {
				// ������������ ���������� ��� ���������� ��������� ����������� ������
				Sx = Sy = aspectFig1 < aspectForm ? Wy / Vy1 : Wx / Vx1;
			}
			else {
				Sx = Wx / Vx1; // ����������� ���������� �� ��� Ox
				Sy = Wy / Vy1; // ����������� ���������� �� ��� Oy
			}

			float Ty = Sy * Vy1; // �������� � ������������� ������� �� ��� Oy ����� ����� �����
			for (int i = 0; i < arrayLength1; i += 4) {
				g->DrawLine(blackPen, Sx * lines1[i], Ty - Sy * lines1[i + 1], Sx * lines1[i + 2], Ty - Sy * lines1[i + 3]);
			}
		}

	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		keepAspectRatio = true; // ��������� ��������: ��������� ����������� ������ �������
		a = true;
		Refresh();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = ClientRectangle.Width / 2.f; // ���������� ������
		float Wcy = ClientRectangle.Height / 2.f; // �������� ����
		switch (e->KeyCode) {
		case Keys::M:
			keepAspectRatio = !keepAspectRatio;
			break;
		case Keys::N:
			a = !a;
			break;
		case Keys::Q:
			T = translate(-Wcx, -Wcy) * T; // ������� ������ ��������� � (Wcx, Wcy)
			T = rotate(0.01f) * T; // ������� �� 0.01 ������ ������������
			// ������ ������
			T = translate(Wcx, Wcy) * T; // ������� ������ ��������� �������
			break; 
		case Keys::W:
			T = translate(0.f, -1.f) * T; // ����� ����� �� ���� ������
			break;
		case Keys::Escape:
			T = mat3(1.f); // ��������� T ��������� �������
			break;
		default:
			break;
		}
		Refresh();
	}
	};
}