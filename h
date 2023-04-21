import tkinter.messagebox
# import all functions from the tkinter
from tkinter import *
# import messagebox class from tkinter
from tkinter import messagebox
import math
import subprocess

# Function for clearing the
# contents of all text entry boxes
def clearAll():
    # deleting the content from the entry box
    moduleField.delete(0, END)
    teethnoField.delete(0, END)
    pangleField.delete(0, END)
    helixField.delete(0, END)
    teeth2Field.delete(0,END)
    rsltodField.config(state=NORMAL)
    rsltpitchdiaField.config(state=NORMAL)
    rsltduanchijuField.config(state=NORMAL)
    rsltrootdiaField.config(state=NORMAL)
    rsltzxjField.config(state=NORMAL)
    rsltduanm_sField.config(state=NORMAL)
    rsltodField.delete(0, END)
    rsltpitchdiaField.delete(0, END)
    rsltduanchijuField.delete(0, END)
    rsltzxjField.delete(0, END)
    rsltrootdiaField.delete(0, END)
    rsltduanm_sField.delete(0, END)
    rsltodField.config(state=DISABLED)
    rsltpitchdiaField.config(state=DISABLED)
    rsltduanchijuField.config(state=DISABLED)
    rsltrootdiaField.config(state=DISABLED)
    rsltzxjField.config(state=DISABLED)
    rsltduanm_sField.config(state=DISABLED)

def comingSoon():
    messagebox.showinfo("coming soon",message="Coming Soon")
# function for checking error
def checkError():
    if (moduleField.get() == "" or teethnoField.get() ==
            "" or pangleField.get() == "" or
            helixField.get() == "" or helixField.get() == ""):
        messagebox.showerror("Input Error")
        clearAll()
        return -1


# function to calculate
def calculate():
    # check for error
    value = checkError()
    # if error is occur then return
    if value == -1:
        return
    else:
        # clear before result
        rsltodField.config(state=NORMAL)
        rsltpitchdiaField.config(state=NORMAL)
        rsltduanchijuField.config(state=NORMAL)
        rsltrootdiaField.config(state=NORMAL)
        rsltzxjField.config(state=NORMAL)
        rsltduanm_sField.config(state=NORMAL)
        rsltodField.delete(0, END)
        rsltpitchdiaField.delete(0, END)
        rsltduanchijuField.delete(0, END)
        rsltzxjField.delete(0, END)
        rsltrootdiaField.delete(0, END)
        rsltduanm_sField.delete(0, END)

        # take a value from the respective entry boxes
        # get method returns current text as string
        moshu = float(moduleField.get())
        teeth_no = float(teethnoField.get())
        # p_angle = float(pangleField.get())
        helix_a = float(helixField.get())
        teeth2 = float(teeth2Field.get())


        # calculate od, pitch dia,across teeth, common normal length

        cal_od = moshu/math.cos(math.radians(helix_a)) * teeth_no + 2 * moshu
        cal_pitchdia = moshu/math.cos(math.radians(helix_a)) * teeth_no
        cal_rootd = cal_pitchdia - 2.5 * moshu
        cal_duanm_s = moshu/math.cos(math.radians(helix_a))
        cal_duanchiju = cal_duanm_s * math.pi
        cal_zxj = cal_duanm_s * 0.5 * (teeth_no + teeth2)
        # calculated od, pitch diameter write back
        # to the respective entry boxes
        # insert method inserting the
        # value in the text entry box.
        rsltodField.insert(10, str("%.2f" % cal_od))
        rsltpitchdiaField.insert(10, str("%.2f" % cal_pitchdia))
        rsltduanchijuField.insert(10,str("%.2f" % cal_duanchiju))
        rsltzxjField.insert(10, str("%.2f" % cal_zxj))
        rsltrootdiaField.insert(10, str("%.2f" % cal_rootd))
        rsltduanm_sField.insert(10, str("%.2f" % cal_duanm_s))
        rsltodField.config(state=DISABLED)
        rsltpitchdiaField.config(state=DISABLED)
        rsltduanchijuField.config(state=DISABLED)
        rsltrootdiaField.config(state=DISABLED)
        rsltzxjField.config(state=DISABLED)
        rsltduanm_sField.config(state=DISABLED)

    # Driver Code


if __name__ == "__main__":
    # 图片转换为py文件
    import base64
    from memory_pic import *


    def get_pic(pic_code, pic_name):
        image = open(pic_name, 'wb')
        image.write(base64.b64decode(pic_code))
        image.close()


    # 产生临时图片，保存在当前目录下
    get_pic(mili_png, 'mili.png')
    get_pic(helical_png, 'helical.png')
    get_pic(logo_ico, 'logo.ico')

    # Create a GUI window
    gui = Tk()
    # Set the background colour of GUI window
    gui.configure(background="lightblue")
    # set the name of tkinter GUI window
    gui.title("Gear Calculator 各种齿轮计算 (by D.R. Feng)")
    # change logo
    gui.iconbitmap("logo.ico")
    # Set the configuration of GUI window
    gui.geometry("720x710+400+100")
    gui.resizable(0,0)
    # 创建一个主目录菜单，也被称为顶级菜单
    main_menu = Menu(gui)
    # 新增命令菜单项，使用 add_command() 实现
    main_menu.add_command(label="Spur gear 圆柱齿轮",background="blue",command=comingSoon)
    main_menu.add_command(label="Helical gear 斜齿轮",command='pass')
    main_menu.add_command(label="Bevel gear 圆锥齿轮",command=comingSoon)
    main_menu.add_command(label="Worm gear 蜗轮蜗杆",command=comingSoon)
    # main_menu.add_command(label="帮助", command=menuCommand)
    # 显示菜单
    gui.config(menu=main_menu)
    # Create a Input 1 : label
    dob = Label(gui, text="Input helical gear data 输入斜齿轮参数",relief= "raised", font="arial", bg="orange")
    # Create a Input 2 : label
    coeff = Label(gui, text="Helix angle 螺旋角 (β=8º~20º)", bg="lightblue").place(x=390,y=70)
    # Create a module : label
    mod_label = Label(gui, text="Radial module 法面模数 (mn)", bg="lightblue").place(x=10,y=70)
    # Create a teeth : label
    teeth_label = Label(gui, text="No of teeth 齿数 (Z1)", bg="lightblue").place(x=10,y=120)
    # Create a pa : label
    pa_label = Label(gui, text="Pressure angle 压力角 (α°)", bg="lightblue").place(x=390,y=120)
    # Create a coefficient : label
    teeth2_Label = Label(gui, text="Mating gear 配对齿轮齿数 （Z2)", bg="lightblue")
    # Create a root diameter : label
    root_dia = Label(gui, text="Root diameter 齿根圆直径（df)", bg="lightblue")
    # Create a tooth thickness : label
    duanm_s = Label(gui, text="Transverse module 端面模数 (mt)", bg="lightblue")

    # Create a OD : label
    resultod = Label(gui, text="Head diameter 齿轮外径 (dɑ)", bg="lightblue")
    # Create a pitch diameter : label
    resultpitchdia = Label(gui, text="Pitch diameter 分度圆直径 (d)", bg="lightblue")
    # Create a across teeth : label
    resultduanchiju = Label(gui, text="Transverse pitch 端面齿距 (Pt)", bg="lightblue")
    # Create a wk : Label
    resultzxj = Label(gui, text="Distance between center 中心距 (a)", bg="lightblue")
    # Create ref & module: Label
    ref = Label(gui,  text="Common P.A 常用压力角:",relief= "raised", bg="orange")
    ref2 = Label(gui,relief= "raised", text="14.5°, 20°, 22.5°, 25°", bg="orange")
    ref1 = Label(gui, text="Common module 常用模数:",relief= "raised", bg="orange")
    ref3 = Label(gui,relief= "raised", text="1, 1.25, 1.5, 2, 2.5, 3, 4, 5, 6", bg="orange")
    ref4 = Label(gui,relief= "raised", text="8, 10, 12, 16, 18, 22,28, 36", bg="orange")
    # Create a calculate Button and attached to calculate function
    start_cal = Button(gui, text="Start calculate 开始计算", relief= "raised",font="arial", fg="yellow", bg="black",
                       command=calculate)

    # 图片转换为py文件
    import base64
    from memory_pic import *


    def get_pic(pic_code, pic_name):
        image = open(pic_name, 'wb')
        image.write(base64.b64decode(pic_code))
        image.close()


    # 产生临时图片，保存在当前目录下
    get_pic(mili_png, 'mili.png')
    get_pic(helical_png, 'helical.png')
    get_pic(logo_ico, 'logo.ico')


    # 拉开间距
    rsltkongge0 = Label(gui, text="       ", bg="lightblue")
    rsltkongge1 = Label(gui, text="       ", bg="lightblue")
    rsltkongge2 = Label(gui, text="       ", bg="lightblue")
    rsltkongge3 = Label(gui, text="       ", bg="lightblue")
    rsltkongge4 = Label(gui, text="       ", bg="lightblue")
    rsltkongge5 = Label(gui, text="============================================="
                                  "===============================", fg='blue',bg="lightblue")
    rsltkongge6 = Label(gui, text="       ", bg="lightblue")
    rsltkongge7 = Label(gui, text="       ", bg="lightblue")
    rsltkongge8 = Label(gui, text="xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
                                  "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
                                  "xxxxxxxxxxxxxxxxxxxxxxxxxx",fg='blue', bg="lightblue")
    rsltkongge9 = Label(gui, text="       ", bg="lightblue")
    rsltkongge10 = Label(gui, text="       ", bg="lightblue")
    # Create a Clear All Button and attached to clearAll function
    clearAllEntry = Button(gui, text="Clear All 全部清除",relief= "raised", font="arial",
                           fg="white", bg="black", command=clearAll)

    moduleField = Entry(gui,bg='yellow')
    teethnoField = Entry(gui,bg='yellow')
    pangleField = Entry(gui,bg='yellow')
    helixField = Entry(gui,bg='yellow')
    teeth2Field = Entry(gui,bg='yellow')
    rsltodField = Entry(gui)
    rsltpitchdiaField = Entry(gui)
    rsltrootdiaField = Entry(gui)
    rsltduanm_sField = Entry(gui)
    rsltduanchijuField = Entry(gui)
    rsltzxjField = Entry(gui)
    rsltodField.config(state=DISABLED)
    rsltpitchdiaField.config(state=DISABLED)
    rsltduanchijuField.config(state=DISABLED)
    rsltrootdiaField.config(state=DISABLED)
    rsltzxjField.config(state=DISABLED)
    rsltduanm_sField.config(state=DISABLED)

    rsltkongge0.grid(row=0, column=1)
    dob.grid(row=1, column=1,columnspan=3)
    rsltkongge1.grid(row=2, column=1)
    # mod_label.grid(row=3, column=0)
    moduleField.grid(row=3, column=1,ipady=3)
    rsltkongge2.grid(row=4, column=1)
    # teeth_label.grid(row=5, column=0)
    teethnoField.grid(row=5, column=1,ipady=3)
    # pa_label.grid(row=5, column=3)
    pangleField.grid(row=5, column=4,ipady=3)
    rsltkongge4.grid(row=6, column=1)
    # coeff.grid(row=3, column=3)
    helixField.grid(row=3, column=4,ipady=3)
    teeth2_Label.grid(row = 7, column=0)
    teeth2Field.grid(row=7,column=1,ipady=3)
    start_cal.grid(row=7, column=2, columnspan=3)
    rsltkongge5.grid(row=8, column=0,columnspan=6)
    resultod.grid(row=9, column=0)
    rsltodField.grid(row=9, column=1,ipady=3)
    resultpitchdia.grid(row=9, column=3)
    rsltpitchdiaField.grid(row=9, column=4,ipady=3)
    rsltkongge6.grid(row=10, column=1)
    root_dia.grid(row=11, column=0)
    rsltrootdiaField.grid(row=11, column=1,ipady=3)
    duanm_s.grid(row=11, column=3)
    rsltduanm_sField.grid(row=11, column=4,ipady=3)
    rsltkongge7.grid(row=12, column=1)
    resultduanchiju.grid(row=13, column=0)
    rsltduanchijuField.grid(row=13,column=1,ipady=3)
    resultzxj.grid(row=13, column=3)
    rsltzxjField.grid(row=13, column=4,ipady=3)

    rsltkongge3.grid(row=14, column=1)
    clearAllEntry.grid(row=16, column=2,columnspan=4)
    rsltkongge8.grid(row=17, column=0,columnspan=6)

    canvas = Canvas()
    canvas2 = Canvas(width=100,height=100)

    img = PhotoImage(file="helical.png")
    canvas.create_image(190, 120, image=img)
    img2 = PhotoImage(file="mili.png")
    canvas2.create_image(50, 50, image=img2)

    ref.grid(row=18, column=4)
    ref2.grid(row=19, column=4)
    canvas.grid(row=18,rowspan=5, column=1,columnspan=3)
    canvas2.grid(row=20, rowspan=2, column=4)
    ref1.grid(row=18, column=0)
    ref3.grid(row=19, column=0)
    ref4.grid(row=20, column=0)



    # Start the GUI
    gui.mainloop()
