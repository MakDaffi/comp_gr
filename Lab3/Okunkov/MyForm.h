#pragma once

namespace Okunkov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	mat3 T = mat3(1.f); // матрица, в которой накапливаются все преобразования
    // первоначально - единичная матрица
	mat3 initT; // матрица начального преобразования

	float lines[] = {
		// голова
		0.5f,3.f,1.f,4.5f, // от левой щеки вверх до уха
		1.f,4.5f,0.5f,6.f, // левое ухо слева снизу вверх
		0.5f,6.f,0.5f, 7.5f, // левое ухо слева
		0.5f, 7.5f,1.f,8.f, // левое ухо верх слева
		1.f,8.f,1.5f,8.f, // левое ухо верх середина
		1.5f,8.f,2.f,7.5f, // левое ухо верх справа
		2.f,7.5f,1.5f, 6.f, // левое ухо справа сверху вниз
		1.5f, 6.f,1.5f,4.5f, // левое ухо справа до макушки
		1.5f,4.5f,3.f,4.5f, // макушка
		3.f,4.5f,3.f,6.f, // правое ухо слева снизу вверх
		3.f,6.f,2.5f,7.5f, // правое ухо слева
		2.5f,7.5f,3.f,8.f, // правое ухо верх слева
		3.f,8.f,3.5f,8.f, // правое ухо верх середина
		3.5f,8.f,4.f,7.5f, // правое ухо верх справа
		4.f,7.5f,4.f,6.f, // правое ухо сверху вниз
		4.f,6.f,3.5f,4.5f, // правое ухо справа
		3.5f,4.5f,4.f,3.f, // от правого уха вниз до щеки
		4.f,3.f,3.5f,1.5f, // правая скула
		3.5f,1.5f,2.5f,1.f, // подбородок справа
		2.5f,1.f,2.f,1.f, // подбородок снизу
		2.f,1.f,1.f,1.5f, // подбородок слева
		1.f,1.5f,0.5f,3.f, // левая скула
		// туловище
		4.f,3.f,5.5f,3.5f, // спина от головы вправо
		5.5f,3.5f,7.f,3.5f, // спина верх
		7.f,3.5f,7.5f,2.5f, // спина сверху до хвоста
		7.5f,2.5f,8.f,2.5f, // хвост сверху
		8.f,2.5f,8.f,2.f, // хвост справа
		8.f,2.f,7.5f,2.f, // хвост низ справа налево
		7.5f,2.f,7.5f,0.5f, // задняя нога справа сверху вниз
		7.5f,0.5f,6.5f,0.5f, // задняя нога низ
		6.5f,0.5f,6.5f,1.f, // задняя нога слева
		6.5f,1.f,6.f,1.f, // между задних ног
		6.f,1.f,6.f,0.5f, // левая задняя нога справа
		6.f,0.5f,5.f,0.5f, // левая задняя нога низ
		5.f,0.5f,5.f,1.f, // левая задняя нога слева
		5.f,1.f,4.f,1.f, // между задними и передними ногами
		4.f,1.f,4.f,0.5f, // правая передняя нога справа
		4.f,0.5f,3.f,0.5f, // правая передняя нога низ
		3.f,0.5f,3.f,1.f, // правая передняя нога слева
		3.f,1.f,2.5f,1.f, // между передних ног
		2.5f,1.f,2.5f,0.5f, // передняя нога справа
		2.5f,0.5f,1.5f,0.5f, // передняя нога низ
		1.5f,0.5f,1.5f,1.25f, // передняя нога слева
		// левый глаз
		1.5f,3.5f,1.5f,3.f, // левый глаз слева сверху вниз
		1.5f,3.f,2.f,3.f, // левый глаз низ
		2.f, 3.f,2.f,3.5f, // левый глаз справа
		2.f,3.5f,1.5f,3.5f, // левый глаз верх
		// правый глаз
		2.5f,3.5f,2.5f,3.f, // правый глаз слева
		2.5f,3.f,3.f, 3.f, // правый глаз снизу
		3.f,3.f,3.f,3.5f, // правый глаз справа
		3.f,3.5f,2.5f,3.5f, // правый глаз сверху
		// ушные раковины
		1.f,5.5f,1.f,7.f, // левая ушная раковина
		3.5f,5.5f,3.5f,7.f, // правая ушная раковина
		// нос
		2.f,2.5f,2.5f,2.5f, // нос сверху
		2.5f,2.5f,2.25f,2.f, // нос справа
		2.25f,2.f,2.f,2.5f // нос слева
	};

	float lines1[] = {
		// лицо
		3.f,12.f,3.f,12.5f,  // левая щека
		3.f,12.5f,4.5f,13.f, // от щеки к глазу
		4.5,13.f,6.5f,13.f,  // линия над глазами
		6.5f,13.f,8.f,12.5f, // от глаза к щеке
		8.f,12.5f,8.f,12.f,  // правая щека
		8.f,12.f,5.5f,10.5f, // правая часть подбородка
		5.5f,10.5f,3.f,12.f, // левая часть подбородка
		// рот
		3.5f,12.f,4.f,12.5f,
		4.f,12.5f,5.f,11.5f,
		5.f,11.5f,6.f,11.5f,
		6.f,11.5f,7.f,12.5,
		7.f,12.5,7.5f,12.f,
		// правый глаза
		4.5,13.f,4.5f,14.f,
		4.5f,14.f,5.f,14.5f,
		5.f,14.5f,5.5f,14.f,
		5.5f,14.f,5.5,13.f,
		// левый глаз
		5.5f,14.f,6.f,14.5f,
		6.f,14.5f,6.5f,14.f,
		6.5f,14.f,6.5f,13.f,
		// правая глазница
		4.75f,13.f,4.75f,13.5f,
		4.75f,13.5f,5.f,14.f,
		5.f,14.f,5.25f,13.5f,
		5.25f,13.5f,5.25,13.f,
		// левая глазница
		5.75f,13.f,5.75f,13.5f,
		5.75f,13.5f,6.f,14.f,
		6.f,14.f,6.25f,13.5f,
		6.25f,13.5f,6.25f,13.f,
		// правый глаз
		4.875f,13.f,4.875f,13.25f,
		4.875f,13.25f,5.f,13.5f,
		5.f,13.5f,5.125f,13.25f,
		5.125f,13.25f,5.125,13.f,
		// левый глаз
		5.875f,13.f,5.875f,13.25f,
		5.875f,13.25f,6.f,13.5f,
		6.f,13.5f,6.125f,13.25f,
		6.125f,13.25f,6.125f,13.f,
		// шея
		4.5f,11.125f,4.5f,10.5f,
		6.5f,11.125f,6.5f,10.5f,
		// бабочка
		4.f,11.f,4.f,9.f,
		4.f,9.f,5.5f,10.5f,
		4.f,11.f,5.5f,9.5f,
		5.5f,9.5f,7.f,11.f,
		7.f,11.f,7.f,9.f,
		7.f,9.f,5.5f,10.5f,
		// правая лапка
		5.5f,9.5f,6.f,7.5f,
		6.f,7.5f,7.f,6.f,
		7.f,6.f,7.f,7.f,
		7.f,7.f,8.f,6.5f,
		8.f,6.5f,7.5f,7.5f,
		7.5f,7.5f,8.5f,8.f,
		8.5f,8.f,7.f,8.f,
		7.f,8.f,6.75f,9.25f,
		// левая лапка
		5.5f,9.5f,5.f,7.5f,
		5.f,7.5f,4.f,6.f,
		4.f,6.f,4.f,7.f,
		4.f,7.f,3.f,6.5f,
		3.f,6.5f,3.5f,7.5f,
		3.5f,7.5f,2.5f,8.f,
		2.5f,8.f,4.f,8.f,
		4.f,8.f,4.25f,9.25f,
		// голова гриба
		1.f,5.5f,10.f,5.5f,
		1.f,5.5f,1.5f,8.5f,
		1.5f,8.5f,2.f,10.f,
		10.f,5.5f,9.5f,8.5f,
		9.5f,8.5f,9.f,10.f,
		// левая задняя лапка
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
		// правая задняя лапка
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
		// ножка гриба
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
		//трава
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
		// пятна на голове гриба
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


	float Vx = 8.5f; // размер рисунка по горизонтали
	float Vy = 8.5f; // размер рисунка по вертикали
	float aspectFig = Vx / Vy; // соотношение сторон рисунка
	float Vx1 = 10.5f; // размер рисунка по горизонтали
	float Vy1 = 15.5f; // размер рисунка по вертикали
	float aspectFig1 = Vx1 / Vy1; // соотношение сторон рисунка

	unsigned int arrayLength = sizeof(lines) / sizeof(float);
	unsigned int arrayLength1 = sizeof(lines1) / sizeof(float);

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
	private: bool keepAspectRatio, a; // значение - сохранять ли соотношение сторон рисунка?
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		if (a) {
			Graphics^ g = e->Graphics;
			g->Clear(Color::Aquamarine);

			Pen^ blackPen = gcnew Pen(Color::Black, 2);

			float Wx = ClientRectangle.Width; //размер окна по горизонтали
			float Wy = ClientRectangle.Height; //размер окна по вертикали

			float aspectForm = Wx / Wy; //соотношение сторон окна рисования
			float Sx, Sy;
			if (keepAspectRatio) {
				// коэффициенты увеличения при сохранении исходного соотношения сторон
				Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
			}
			else {
				Sx = Wx / Vx; // коэффициент увеличения по оси Ox
				Sy = Wy / Vy; // коэффициент увеличения по оси Oy
			}

			float Ty = Sy * Vy; // смещение в положительную сторону по оси Oy после смены знака
			initT = translate(0.f, Ty) * scale(Sx, -Sy); // преобразования применяются справа налево
            // сначала масштабирование, а потом перенос
            // в initT совмещаем эти два преобразования
			mat3 M = T * initT; // совмещение начального преобразования и
			// накопленных преобразований
			for (int i = 0; i < arrayLength; i += 4) {
				vec3 A = vec3(lines[i], lines[i + 1], 1.f); // начало отрезка в однородных координатах
				vec3 B = vec3(lines[i + 2], lines[i + 3], 1.f); // конец отрезка в однородных координатах
				vec2 a = normalize(M * A); // начало отрезка после преобразования
				vec2 b = normalize(M * B); // конец отрезка после преобразования
				g->DrawLine(blackPen, a.x, a.y, b.x, b.y); // отрисовка отрезка
			}
		}
		else {
			Graphics^ g = e->Graphics;
			g->Clear(Color::Red);

			Pen^ blackPen = gcnew Pen(Color::Black, 2);

			float Wx = ClientRectangle.Width; //размер окна по горизонтали
			float Wy = ClientRectangle.Height; //размер окна по вертикали

			float aspectForm = Wx / Wy; //соотношение сторон окна рисования
			float Sx, Sy;
			if (keepAspectRatio) {
				// коэффициенты увеличения при сохранении исходного соотношения сторон
				Sx = Sy = aspectFig1 < aspectForm ? Wy / Vy1 : Wx / Vx1;
			}
			else {
				Sx = Wx / Vx1; // коэффициент увеличения по оси Ox
				Sy = Wy / Vy1; // коэффициент увеличения по оси Oy
			}

			float Ty = Sy * Vy1; // смещение в положительную сторону по оси Oy после смены знака
			for (int i = 0; i < arrayLength1; i += 4) {
				g->DrawLine(blackPen, Sx * lines1[i], Ty - Sy * lines1[i + 1], Sx * lines1[i + 2], Ty - Sy * lines1[i + 3]);
			}
		}

	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		keepAspectRatio = true; // начальное значение: сохранять соотношение сторон рисунка
		a = true;
		Refresh();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = ClientRectangle.Width / 2.f; // координаты центра
		float Wcy = ClientRectangle.Height / 2.f; // текущего окна
		switch (e->KeyCode) {
		case Keys::M:
			keepAspectRatio = !keepAspectRatio;
			break;
		case Keys::N:
			a = !a;
			break;
		case Keys::Q:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в (Wcx, Wcy)
			T = rotate(0.01f) * T; // поворот на 0.01 радиан относительно
			// нового центра
			T = translate(Wcx, Wcy) * T; // перенос начала координат обратно
			break; 
		case Keys::W:
			T = translate(0.f, -1.f) * T; // сдвиг вверх на один пиксел
			break;
		case Keys::Escape:
			T = mat3(1.f); // присвоили T единичную матрицу
			break;
		default:
			break;
		}
		Refresh();
	}
	};
}