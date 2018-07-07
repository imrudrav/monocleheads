//
//  ViewController.swift
//  FenceGUI
//
//  Created by Tanner Orndorff on 6/21/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBAction func changeBackground(_ sender: Any) {
        let temp = view.subviews
        for each in temp {
            if each is UISwitch {
                let currentSwitch = each as! UISwitch
                if(currentSwitch.isOn)
                {
                    //change view background to black / yellow
                    view.backgroundColor = UIColor.black
                    //get all the labels
                    let everything = view.subviews
                    for everyView in everything {
                        if everyView is UILabel {
                            let currentLabel = everyView as! UILabel
                            currentLabel.textColor = UIColor.yellow;
                        }
                    }
                }
                else
                {
                    //change view to whit and black
                    view.backgroundColor = UIColor.white
                    //get all the labels
                    let everything = view.subviews
                    for everyView in everything {
                        if everyView is UILabel {
                            let currentLabel = everyView as! UILabel
                            currentLabel.textColor = UIColor.black;
                        }
                    }
                }
            }
        }
        
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

